#pragma once
#include "common/common.h"
#include <list>
#include <string>
class Parser {
public:
    static std::list<Class> parse(std::list<std::string> file_names);
private:
};