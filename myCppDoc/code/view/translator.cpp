#include "translator.h"
#include "SetFont.h"

#include <QFont>
#include <QPainter>
#include <QFontMetrics>

Block Translator::classToBlock(const shared_ptr<Class> c) {
	QFont font;
	SetNameFont(font);
	QFontMetrics Metrics(font);
	int width = Metrics.width(QString::fromStdString(c->getName())), height = Metrics.height();
	vector<string> attr = c->getComponents();
	vector<string> func = c->getFunctions();
	SetAttributeFont(font);
	Metrics = QFontMetrics(font);
	height += 4;
	if (attr.size() == 0)height += 5;
	for (int i = 0;i < attr.size();++i) {
		//width is the longest string width of the attributes
		width = max(width, Metrics.width(QString::fromStdString(attr[i])));
		height += Metrics.height()+2;
	}
	height += 4;
	if (func.size() == 0)height += 5;
	for (int i = 0; i < func.size(); ++i) {
		//width is the longest string width of the attributes
		width = max(width, Metrics.width(QString::fromStdString(func[i])));
		height += Metrics.height() + 2;
	}
	height += 4;
	if (attr.size() == 0)width*=2;
	return Block(width*1.3, height, *c);
}

set<Block> Translator::toBlockSet(const list<shared_ptr <Class>>& lis) {
	set<Block> res;
	for (auto i = lis.begin();i != lis.end();++i) {
		res.insert(classToBlock(*i));
	}
	return res;
}