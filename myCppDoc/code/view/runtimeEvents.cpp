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
	Status->showMessage("Load file(s)");
	return 1;
}

bool myCppDoc::FileSaveAsHovered() {
	Status->showMessage("Save the image as bmp format");
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
	if (filelist.size() == 0) {
		SendMsg("No valid file selected.");
		return 1;
	}
	scroll = new QScrollArea(this);
	draw = new drawArea(this, Translator().toBlockSet(Parser::parse(filelist)));
	draw->setGeometry(0, 0, 1200, 800);
	scroll->setWidget(draw);
	scroll->setGeometry(0, 65, 1000, 710);
	scroll->show();
	return 1;
}

QStringList myCppDoc::getAllFiles(const QDir& dir) {
	QStringList path = dir.entryList();
	QStringList ret;
	for (auto i = path.begin();i != path.end();++i) {
		QString filepath = dir.absoluteFilePath(*i);
		if (*i == ".") continue;
		if (*i == "..") continue;
		QFileInfo info(filepath);
		if (info.isDir()) ret += getAllFiles(filepath);
		else ret.push_back(dir.absoluteFilePath(*i));
	}
	return ret;
}

bool myCppDoc::FileLoadFolderManagement() {
	QDir directory(QFileDialog::getExistingDirectory());
	QStringList path = getAllFiles(directory);
	list<string> filelist;
	for (auto i = path.begin();i != path.end();++i) {
		if (!isProjectFileName(*i)) continue;
		filelist.push_back(directory.absoluteFilePath(*i).toStdString());
	}
	if (filelist.size() == 0) {
		SendMsg("No valid file selected.");
		return 1;
	}
	scroll = new QScrollArea(this);
	draw = new drawArea(this, Translator().toBlockSet(Parser::parse(filelist)));
	draw->setGeometry(0, 0, 1200, 800);
	scroll->setWidget(draw);
	scroll->setGeometry(0, 65, 1000, 710);
	scroll->show();
	return 1;
}

bool myCppDoc::FileSaveAsManagement() {
	if (draw == Q_NULLPTR) return 1;
	QString path = QFileDialog::getSaveFileName(this, "save as", "untitled.bmp", "Image(.bmp)");
	if (path != ""){
		QImage image = draw->grabFramebuffer();
		image.save(path, "BMP");
		return 1;
	}
	return 1;
}

bool myCppDoc::HelpInfoManagement() {
	//todo
	return 1;
}