#include "translator.h"
#include <QFont>
#include <QPainter>
#include <QFontMetrics>

Translator::Translator(const QFont& font)
	:font(font){
}

Block Translator::classToBlock(const Class& c) {
	QFontMetrics Metrics(font);
	QString Qstr = QString::fromStdString(c.getName());
	int width = Metrics.width(Qstr), height = Metrics.height();
	vector<string> attr = c.getAttributes();
	for (int i = 0;i < attr.size();++i) {
		Qstr = QString::fromStdString(attr[i]);
		width = max(width, Metrics.width(Qstr));
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