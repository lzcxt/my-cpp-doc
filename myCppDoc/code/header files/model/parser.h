#pragma once
#include <list>
#include <string>
#include "common.h"

/**
 *	
 */
class Parser {
public:
    static std::list<Class> parse(std::list<std::string> file_names);
private:
};