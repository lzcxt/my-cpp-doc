#include "common.h"
#include "cmFunctions.h"
#include <QString>
#include <QMessageBox>

Block::Block(const int& w, const int& h, const Class& c)
	:width(w),height(h),this_class(c){
}


bool Block::operator<(const Block& np) const {
	return this_class.getName() < np.getThisClass().getName();
}

int Block::getWidth() const{
	return width;
}

int Block::getHeight() const {
	return height;
}

Class Block::getThisClass() const {
	return this_class;
}

string Class::getName() const {
	return name;
}
vector<string> Class::getAttributes() const {
	return attributes;
}
list<Relation> Class::getListOfEdges() const {
	return list_edges;
}

bool isProjectFileName(QString s) {
	if (s.contains("*.cpp")) return 1;
	if (s.contains("*.h")) return 1;
	if (s.contains("*.c")) return 1;
	return 0;
}

void Class::setName(string name_) {
	name = name_;
}
void Class::addAttributes(string attr) {
	attributes.push_back(attr);
}
void Class::addRelation(Relation rela) {
	list_edges.push_back(rela);
}

int SendMsg(string x) {
	QMessageBox msg;
	msg.setWindowTitle("Message");
	msg.setText(QString::fromStdString(x));
	msg.setIcon(QMessageBox::Information);
	msg.setStandardButtons(QMessageBox::Ok);
	if (msg.exec() == QMessageBox::Ok) {
		return 1;
	}
	return 0;
}