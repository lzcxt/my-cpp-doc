#include "translator.h"
#include <QFont>
#include <QPainter>
#include <QFontMetrics>

Translator::Translator(const QFont& font)
	:font(font){
}

Block Translator::classToBlock(const Class& c) {
	QFontMetrics Metrics(font);
	int width = Metrics.width(QString::fromStdString(c.getName())), height = Metrics.height();
	vector<string> attr = c.getAttributes();
	for (int i = 0;i < attr.size();++i) {
		width = max(width, Metrics.width(QString::fromStdString(attr[i])));
		height += Metrics.height();
	}
	return Block(width, height, c);
}

set<Block> Translator::toBlockSet(const list<Class>& lis) {
	set<Block> res;
	for (auto i = lis.begin();i != lis.end();++i) {
		res.insert(classToBlock(*i));
	}
	return res;
}