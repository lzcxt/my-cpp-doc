#include "myCppDoc.h"
#include "parser.h"
#include "cmFunctions.h"
#include "translator.h"

#include <list>

#include <QMessageBox>
#include <QFileDialog>
using namespace std;

bool myCppDoc::FileLoadManagement() {
	QStringList path = QFileDialog::getOpenFileNames();
	list<string> filelist;
	for (auto i = path.begin();i != path.end();++i) {
		if (!isProjectFileName(*i)) continue;
		filelist.push_back(i->toStdString());
	}
	set<Block> empty;
	drawArea* draw= new drawArea(0, empty/*Translator(QFont()).toBlockSet(Parser::parse(filelist))*/);
	draw->resize(1200, 800);
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
	drawArea* draw = new drawArea(this, Translator(QFont()).toBlockSet(Parser::parse(filelist)));
	draw->resize(1200, 800);
	draw->show();
	return 1;
}

bool myCppDoc::HelpInfoManagement() {
	//todo
	return 1;
}