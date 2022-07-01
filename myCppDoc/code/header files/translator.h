#pragma once

#include "common.h"
#include <set>
#include <QFont>

class Translator {
private:
	QFont font;

	Block classToBlock(const Class& c);
public:
	Translator(const QFont& font);

	set<Block> toBlockSet(const list<Class>& lis);
};