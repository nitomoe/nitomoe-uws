#ifndef __ENV_H__
#define __ENV_H__

#include <string>

class Env
{
public:
    static const std::string getString(const std::string &key, const std::string &defaultValue = "");
    static const int getInt(const std::string &key, const int defaultValue = 0);
};

#endif