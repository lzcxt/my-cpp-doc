#include "myCppDoc.h"

#include <list>

#include <QMessageBox>
#include <QFileDialog>
using namespace std;

bool myCppDoc::FileLoadManagement() {
	QStringList path = QFileDialog::getOpenFileNames();
	list<string> filelist;
	for (auto i = path.begin();i != path.end();++i) {
		filelist.push_back(i->toStdString());
	}
	//todo
	return 1;
}

bool myCppDoc::HelpInfoManagement() {
	return 1;
}