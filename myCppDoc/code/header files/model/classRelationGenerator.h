#pragma once
#include <string>
#include "common.h"

/**
 * this class use an automation to process the word
 */
class ClassRelationGenerator {
public:
	void pushBack(std::string);
	std::list<Class> getClasses();
private:
	std::list<Class> cls;
};