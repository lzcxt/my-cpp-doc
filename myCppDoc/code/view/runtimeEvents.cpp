#include "myCppDoc.h"
#include "parser.h"
#include "cmFunctions.h"
#include "translator.h"
#include "scrollArea.h"

#include <list>

#include <QMessageBox>
#include <QFileDialog>
#include <QScrollBar>
#include <QCheckBox>
using namespace std;

bool myCppDoc::FileLoadHovered() {
	Status->showMessage("Load file(s)");
	return 1;
}

bool myCppDoc::FileSaveAsHovered() {
	Status->showMessage("Save the image as bmp format");
	return 1;
}

void myCppDoc::formSelect(const set<Block>& Blocks){
	/*QLabel* label=new QLabel(this);
	label->setText("Select displayed classes:");
	label->setGeometry(rect().width() - 200, MenuBar->rect().height() + ToolBar->rect().height(), 200,
		MenuBar->rect().height() + ToolBar->rect().height());
	label->show();
	int checkcnt = 0;
	for (auto i = Blocks.begin();i != Blocks.end();++i) {
		QCheckBox* check = new QCheckBox(this);
		check->setText(QString::fromStdString(i->getThisClass().getName()));
		check->setGeometry()
		Select->addWidget(check);
	}*/
}

void myCppDoc::showGraph(const list<string>& filelist) {
	set<Block> Blocks = Translator().toBlockSet(Parser::parse(filelist));
	formSelect(Blocks);
	scroll = new scrollArea(this);
	draw = new drawArea(this, Blocks);
	draw->setGeometry(0, 0, 1600, 1200);
	draw->setMinimumSize(1200, 900);
	scroll->setWidget(draw);
	scroll->setGeometry(0, MenuBar->rect().height() + ToolBar->rect().height(), rect().width() - 200, 
		rect().height() - Status->rect().height() - MenuBar->rect().height() - ToolBar->rect().height());
	scroll->show();
}

bool myCppDoc::FileLoadManagement() {
	QStringList path = QFileDialog::getOpenFileNames(this,"open","","C++ Project files (*.cpp *.h *.c)");
	if (path.size() == 0) return 1;
	list<string> filelist;
	for (auto i = path.begin();i != path.end();++i) {
		if (!isProjectFileName(*i)) continue;
		filelist.push_back(i->toStdString());
	}
	if (filelist.size() == 0) {
		SendMsg("No valid file selected.");
		return 1;
	}
	showGraph(filelist);
	return 1;
}

QStringList myCppDoc::getAllFiles(const QDir& dir) {
	QStringList path = dir.entryList();
	QStringList ret;
	for (auto i = path.begin();i != path.end();++i) {
		if (*i == ".") continue;
		if (*i == "..") continue;
		QString filepath = dir.absoluteFilePath(*i);
		QFileInfo info(filepath);
		if (info.isDir()) ret += getAllFiles(filepath);
		else ret.push_back(dir.absoluteFilePath(*i));
	}
	return ret;
}

bool myCppDoc::FileLoadFolderManagement() {
	QString getDir = QFileDialog::getExistingDirectory();
	if (getDir == "") return 1;
	QDir directory(getDir);
	QStringList path = getAllFiles(directory);
	list<string> filelist;
	for (auto i = path.begin();i != path.end();++i) {
		if (!isProjectFileName(*i)) continue;
		filelist.push_back(directory.absoluteFilePath(*i).toStdString());
	}
	if (filelist.size() == 0) {
		SendMsg("No valid file found.");
		return 1;
	}
	showGraph(filelist);
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
	SendMsg("MyCppDoc v0.1");
	return 1;
}