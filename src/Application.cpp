#include <uWebSockets/App.h>
#include <nlohmann/json.hpp>
#include <Application.h>
#include <algorithm>
#include <thread>
#include <Env.h>
#include <Log.h>

using HttpResponse = uWS::HttpResponse<false>;
using HttpRequest = uWS::HttpRequest;
using json = nlohmann::json;

Application::Application()
{
    m_port = Env::getInt("PORT", 3000);
}

int Application::run(int argc, char **argv)
{
    LOG_INFO("Starting server on port " << m_port);

    std::vector<std::thread*> threads(std::thread::hardware_concurrency());

    std::transform(threads.begin(), threads.end(), threads.begin(), [&](std::thread *t) {
        return new std::thread([&]() {
            uWS::App()
            .get("/", [](HttpResponse *res, HttpRequest *req) {
                res->end("Hello world!");
            })
            .get("/test", [](HttpResponse *res, HttpRequest *req) {
                res->end("Test");
            })
            .get("/json", [](HttpResponse *res, HttpRequest *req) {
                res->writeHeader("Content-Type", "application/json");
                json json;
                json["hello"] = "world";
                res->end(json.dump());
            })
            .get("/html", [](HttpResponse *res, HttpRequest *req) {
                res->writeHeader("Content-Type", "text/html");
                res->end("<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><title>Test</title></head><body><p><strong>Hello, world!</strong></p></body></html>");
            })
            .get("/*", [](HttpResponse *res, HttpRequest *req) {
                res->writeStatus("404 Not Found");
                res->end("404");
            })
            .listen(m_port, [](us_listen_socket_t *token) {
                if (token) {
                    LOG_INFO("Thread " << std::this_thread::get_id() << " started");
                }
                else {
                    LOG_INFO("Thread " << std::this_thread::get_id() << " failed to start");
                }
            }).run();
        });
    });

    std::for_each(threads.begin(), threads.end(), [](std::thread *t) {
        t->join();
    });

    return 0;
}