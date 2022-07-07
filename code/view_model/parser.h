#pragma once
#include "../common/common.h"
#include <list>
#include <string>
#include <memory>
class Parser {
public:
    const std::list<shared_ptr<Class>>& parse(std::list<std::string> file_names);
private:
};
