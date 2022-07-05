#include "common/common.h"
#include "common/cmFunctions.h"
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

void Block::setWidth(int w){
	width = w;
}

void Block::setHeight(int h){
	height = h;
}

Class Block::getThisClass() const {
	return this_class;
}

bool isProjectFileName(const QString& s) {
	string str = s.toStdString();
	int len = str.length();
	if (str.substr(len - 4, len) == ".cpp") return 1;
	if (str.substr(len - 2, len) == ".h") return 1;
	if (str.substr(len - 2, len) == ".c") return 1;
	return 0;
}

int SendMsg(const string& x) {
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