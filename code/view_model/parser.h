#pragma once
#include "../common/common.h"

class Parser {
public:
    fileProcessor get_fileProcessor();
private:
    std::list<shared_ptr<Class>> classes;
};
