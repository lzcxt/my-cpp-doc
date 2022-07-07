#pragma once

#include <string>
#include "../common/common.h"
#include <queue>
#include <memory>
#include <map>

/**
 * this class use to seperate the cpp file into word
 */
class CppFileContent {
public:
	CppFileContent() {}
    void pushBack(std::string file_content);
    void getClasses(std::list<shared_ptr<Class>>& classes);
private:
	std::map<std::string, shared_ptr<Class> > name2class;
};
