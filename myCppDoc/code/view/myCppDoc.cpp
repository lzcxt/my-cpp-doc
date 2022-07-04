#include "myCppDoc.h"

myCppDoc::myCppDoc(QWidget *parent)
    : QMainWindow(parent) {

	resize(1200, 800);
	
	MenuBar = menuBar();
	ToolBar = addToolBar("Standard");

	FileMenu = MenuBar->addMenu("File");
	OperationMenu = MenuBar->addMenu("Operation");
	HelpMenu = MenuBar->addMenu("Help");

	FileLoad = new QAction(QIcon("textures/open.png"), "Load File", this);
	FileLoad->setShortcut(Qt::CTRL + Qt::Key_I);
	FileMenu->addAction(FileLoad);
	connect(FileLoad, SIGNAL(triggered()), this, SLOT(FileLoadManagement()));

	FileLoadFolder = new QAction(QIcon("textures/open.png"), "Load Folder", this);
	FileLoadFolder->setShortcut(Qt::CTRL + Qt::Key_O);
	FileMenu->addAction(FileLoadFolder);
	connect(FileLoadFolder, SIGNAL(triggered()), this, SLOT(FileLoadFolderManagement()));

	FileSaveAs = new QAction(QIcon("textures/save.png"), "Save as", this);
	FileSaveAs->setShortcut(Qt::CTRL + Qt::Key_S);
	FileMenu->addAction(FileSaveAs);
	connect(FileSaveAs, SIGNAL(triggered()), this, SLOT(FileSaveAsManagement()));


	HelpInfo = new QAction(QIcon("textures/info.png"), "Information", this);
	HelpInfo->setShortcut(Qt::CTRL + Qt::Key_H);
	HelpMenu->addAction(HelpInfo);
	connect(HelpInfo, SIGNAL(triggered()), this, SLOT(HelpInfoManagement()));

	ToolBar->addAction(FileLoad);
	connect(FileLoad, SIGNAL(hovered()), this, SLOT(FileLoadHovered()));
	ToolBar->addAction(FileSaveAs);
	connect(FileSaveAs, SIGNAL(hovered()), this, SLOT(FileSaveAsHovered()));
	ToolBar->addAction(HelpInfo);

	Status = new QStatusBar();
	Status->setSizeGripEnabled(1);
	Status->showMessage("Hello, this is your cute status bar.");
	setStatusBar(Status);

	scroll = Q_NULLPTR;
	draw = Q_NULLPTR;
}

myCppDoc::~myCppDoc() {
}
