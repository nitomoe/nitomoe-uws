#ifndef __ELEMENT_H__
#define __ELEMENT_H__

#include <string>
#include <vector>

class Element
{
private:
    std::string m_tag;
    std::string m_html;
    std::vector<Element> m_children;
    std::vector<std::pair<std::string, std::string>> m_attrs;
public:
    Element(const std::string &tag);
    void attr(const std::string &key, const std::string &val);
    void addChild(const Element &element);
    void html(const std::string &html);
    const std::string render();
};

#endif