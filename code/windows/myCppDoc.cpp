#include "myCppDoc.h"

myCppDoc::myCppDoc(QWidget *parent)
    : QMainWindow(parent) {

	resize(1200, 900);
	
	MenuBar = menuBar();
	ToolBar = addToolBar("Standard");

	FileMenu = MenuBar->addMenu("File");
	OperationMenu = MenuBar->addMenu("Operation");
	HelpMenu = MenuBar->addMenu("Help");

    FileLoad = new QAction(QIcon(":/myCppDoc/open.png"), "Load File", this);
	FileLoad->setShortcut(Qt::CTRL + Qt::Key_I);
	FileMenu->addAction(FileLoad);

    FileLoadFolder = new QAction(QIcon(":/myCppDoc/open.png"), "Load Folder", this);
	FileLoadFolder->setShortcut(Qt::CTRL + Qt::Key_O);
	FileMenu->addAction(FileLoadFolder);

    FileSaveAs = new QAction(QIcon(":/myCppDoc/save.png"), "Save as", this);
	FileSaveAs->setShortcut(Qt::CTRL + Qt::Key_S);
	FileMenu->addAction(FileSaveAs);


    HelpInfo = new QAction(QIcon(":/myCppDoc/info.png"), "Information", this);
	HelpInfo->setShortcut(Qt::CTRL + Qt::Key_H);
	HelpMenu->addAction(HelpInfo);

	ToolBar->addAction(FileLoad);
	ToolBar->addAction(FileSaveAs);
	ToolBar->addAction(HelpInfo);

	Status = new QStatusBar(this);
	Status->setSizeGripEnabled(0);
	Status->showMessage("Hello, this is your cute status bar.");
	setStatusBar(Status);

	parser = new Parser();

	scroll = Q_NULLPTR;
	draw = Q_NULLPTR;

	Binding();
}

myCppDoc::~myCppDoc() {
}
