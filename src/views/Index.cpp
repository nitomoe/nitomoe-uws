#include <views/Index.h>
#include <Element.h>
#include <inja.hpp>

IndexView::IndexView()
{

}

const std::string IndexView::renderInja()
{
    return inja::render("<strong>Hello, world!</strong>", {});
}

const std::string IndexView::render()
{
    Element divElement("div");

    divElement.attr("style", "font-weight: bold;");

    Element pElement("p");
    pElement.html("Hello, world!");

    divElement.addChild(pElement);

    return divElement.render();
//     constexpr auto document = R"(<!DOCTYPE html>
// <html lang="en">
// <head>
//     <meta charset="UTF-8">
//     <meta name="viewport" content="width=device-width, initial-scale=1.0">
//     <title>Nitomoe</title>
// </head>
// <body>
//     <div class="main-content">
//         <p style="font-weight: bold;">Hello, world!</p>
//     </div>
// </body>
// </html>
//     )";

//     return document;
}