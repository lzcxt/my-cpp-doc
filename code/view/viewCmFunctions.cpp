#include "../common/common.h"
#include "viewCmFunctions.h"
#include <QString>
#include <QMessageBox>

bool isProjectFileName(const QString& s) {
	string str = s.toStdString();
    size_t len = str.length();
    if (len >= 4 && str.substr(len - 4, len) == ".cpp") return 1;
    if (len >= 2 && str.substr(len - 2, len) == ".h") return 1;
    if (len >= 2 && str.substr(len - 2, len) == ".c") return 1;
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
