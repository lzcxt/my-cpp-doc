#pragma once
#include <string>
#include "common.h"
#include "cppFileContent.h"

/**
 * this class use an automation to process the word
 */
class ClassRelationGenerator {
public:
	void pushBack(TOKEN t);
	std::list<Class> getClasses();
private:
	std::list<Class> cls;
};