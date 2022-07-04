#include "myCppDoc.h"
#include "parser.h"
#include "cmFunctions.h"
#include "translator.h"

#include <list>

#include <QMessageBox>
#include <QFileDialog>
#include <QScrollArea>
using namespace std;

bool myCppDoc::FileLoadHovered() {
	Status->showMessage("Load File(s)");
	return 1;
}

void myCppDoc::mouseMoveEvent() {
	//todo
}

bool myCppDoc::FileLoadManagement() {
	QStringList path = QFileDialog::getOpenFileNames();
	list<string> filelist;
	for (auto i = path.begin();i != path.end();++i) {
		if (!isProjectFileName(*i)) continue;
		filelist.push_back(i->toStdString());
	}
	if (scroll != Q_NULLPTR) delete scroll;
	scroll = new QScrollArea(this);
	if (draw != Q_NULLPTR) delete draw;
	draw = new drawArea(this, Translator().toBlockSet(Parser::parse(filelist)));
	draw->setGeometry(0, 0, 1200, 800);
	scroll->setWidget(draw);
	scroll->setGeometry(0, 65, 1000, 710);
	scroll->show();
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
	if (scroll != Q_NULLPTR) delete scroll;
	scroll = new QScrollArea(this);
	if (draw != Q_NULLPTR) delete draw;
	draw = new drawArea(this, Translator().toBlockSet(Parser::parse(filelist)));
	draw->setGeometry(0, 0, 1200, 800);
	scroll->setWidget(draw);
	scroll->setGeometry(0, 65, 1000, 710);
	scroll->show();
	return 1;
}

bool myCppDoc::FileSaveAsManagement() {
	QString path = QFileDialog::getSaveFileName(this, "save as", "untitled.bmp", "Image(.bmp)");
	if (path == "") return 1;
	if (draw == Q_NULLPTR) throw m_Exception("No opened files.");
	else {
		QImage image = draw->grabFramebuffer();
		image.save(path, "BMP");
		return 1;
	}
	return 0;
}

bool myCppDoc::HelpInfoManagement() {
	//todo
	return 1;
}