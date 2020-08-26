#include <Env.h>
#include <cstdlib>

const std::string Env::getString(const std::string &key, const std::string &defaultValue)
{
    char *c = std::getenv(key.c_str());

    return c != nullptr ? std::string(c) : defaultValue;
}

const int Env::getInt(const std::string &key, const int defaultValue)
{
    char *c = std::getenv(key.c_str());

    if (c == nullptr) {
        return defaultValue;
    }

    return atoi(c);
}