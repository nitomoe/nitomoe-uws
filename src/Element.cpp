#include <Element.h>
#include <sstream>
#include <Log.h>

Element::Element(const std::string &tag) :
    m_tag(tag)
{
}

void Element::html(const std::string &html)
{
    m_html = html;
}

void Element::attr(const std::string &key, const std::string &val)
{
    m_attrs.push_back({key, val});
}

void Element::addChild(const Element &element)
{
    m_children.push_back(element);
}

const std::string Element::render()
{
    std::ostringstream oss;
    oss << "<" << m_tag;

    for (const auto &attr : m_attrs) {
        oss << " " << attr.first << "=\"" << attr.second << "\"";
    }

    oss << ">";

    if (m_html.size() > 0) {
        oss << m_html;
    }

    for (auto &child : m_children) {
        oss << child.render();
    }

    oss << "</" << m_tag << ">";

    return oss.str();
}