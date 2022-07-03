#pragma once

#include "common.h"
#include <set>

class Translator {
private:
	Block classToBlock(const Class& c);
public:
	set<Block> toBlockSet(const list<Class>& lis);
};