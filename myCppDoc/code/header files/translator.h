#pragma once

#include "common.h"
#include <set>
#include <QFont>

class translator {
private:
	QFont font;

	Block classToBlock(const Class& c);
public:
	translator(const QFont& font);

	set<Block> toBlockSet(const list<Class>& lis);
};