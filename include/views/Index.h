#ifndef __VIEWS_INDEX_H__
#define __VIEWS_INDEX_H__

#include <string_view>
#include <string>

class IndexView
{
public:
    IndexView();
    const std::string render();
    const std::string renderInja();
};

#endif