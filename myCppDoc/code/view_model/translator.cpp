#include "translator.h"
#include <QFont>
#include <QPainter>
#include <QFontMetrics>

translator::translator(const QFont& font)
	:font(font){
}

Block translator::classToBlock(const Class& c) {
	QFontMetrics Metrics(font);
	QString Qstr = QString::fromStdString(c.name);
	int width = Metrics.width(Qstr), height = Metrics.height();
	for (int i = 0;i < c.attributes.size();++i) {
		Qstr = QString::fromStdString(c.attributes[i]);
		width = max(width, Metrics.width(Qstr));
		height += Metrics.height();
	}
	return Block(width, height, c);
}

set<Block> translator::toBlockSet(const list<Class>& lis) {
	set<Block> res;
	for (auto i = lis.begin();i != lis.end();++i) {
		res.insert(classToBlock(*i));
	}
	return res;
}