#include "myCppDoc.h"
#include "parser.h"
#include "common/cmFunctions.h"
#include "translator.h"

#include <list>

#include <QMessageBox>
#include <QFileDialog>
using namespace std;

bool myCppDoc::FileLoadHovered() {
	Status->showMessage("Load File(s)");
	return 1;
}

bool myCppDoc::FileLoadManagement() {
	QStringList path = QFileDialog::getOpenFileNames();
	list<string> filelist;
	for (auto i = path.begin();i != path.end();++i) {
		if (!isProjectFileName(*i)) continue;
		filelist.push_back(i->toStdString());
	}
	//drawArea* draw=new drawArea(0, Translator().toBlockSet(Parser::parse(filelist)));
	//draw->resize(800, 1200);
	drawArea* draw = new drawArea(this, Translator().toBlockSet(Parser::parse(filelist)));
	draw->setGeometry(0, 65, 1200, 710);
	draw->show();
	return 1;
}

bool myCppDoc::FileLoadFolderManagement() {
	QDir directory(QFileDialog::getExistingDirectory());
	QStringList path = directory.entryList();
	list<string> filelist;
	for (auto i = path.begin();i != path.end();++i) {
		if (!isProjectFileName(*i)) continue;
		filelist.push_back(i->toStdString());
	}
	drawArea draw(0, Translator().toBlockSet(Parser::parse(filelist)));
	draw.resize(800, 1200);
	draw.show();
	return 1;
}

bool myCppDoc::HelpInfoManagement() {
	//todo
	return 1;
}