#include "myCppDoc.h"

myCppDoc::myCppDoc(QWidget *parent)
    : QMainWindow(parent) {

	resize(600, 400);
	
	MenuBar = menuBar();
	ToolBar = addToolBar("Standard");

	FileMenu = MenuBar->addMenu("File");
	OperationMenu = MenuBar->addMenu("Operation");
	HelpMenu = MenuBar->addMenu("Help");

	FileLoad = new QAction(QIcon("textures/open.png"), "Load", this);
	FileLoad->setShortcut(Qt::CTRL + Qt::Key_I);
	FileMenu->addAction(FileLoad);
	connect(FileLoad, SIGNAL(triggered()), this, SLOT(FileLoadManagement()));

	FileLoadFolder = new QAction(QIcon("textures/open.png"), "Load Folder", this);
	FileLoadFolder->setShortcut(Qt::CTRL + Qt::Key_O);
	FileMenu->addAction(FileLoadFolder);
	connect(FileLoadFolder, SIGNAL(triggered()), this, SLOT(FileLoadFolderManagement()));

	HelpInfo = new QAction(QIcon("textures/info.png"), "Information", this);
	HelpInfo->setShortcut(Qt::CTRL + Qt::Key_H);
	HelpMenu->addAction(HelpInfo);
	connect(HelpInfo, SIGNAL(triggered()), this, SLOT(HelpInfoManagement()));

	ToolBar->addAction(FileLoad);
	ToolBar->addAction(HelpInfo);

	Label = new QLabel(this);
	Label->setGeometry(0,this->rect().height()-35,this->rect().width(),35);
}

myCppDoc::~myCppDoc() {
}
