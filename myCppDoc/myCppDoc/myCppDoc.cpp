#include "myCppDoc.h"

myCppDoc::myCppDoc(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	MenuBar = menuBar();
	ToolBar = addToolBar("Standard");

	FileMenu = MenuBar->addMenu("File");
	OperationMenu = MenuBar->addMenu("Operation");
	HelpMenu = MenuBar->addMenu("Help");

	FileLoad = new QAction(QIcon("./textures/open.png"), "Load", this);
	FileLoad->setShortcut(Qt::CTRL + Qt::Key_I);
	FileMenu->addAction(FileLoad);
	connect(FileLoad, SIGNAL(triggered()), this, SLOT(FileLoadManagement()));

	HelpInfo = new QAction(QIcon("./textures/info.png"), "Help", this);
	HelpInfo->setShortcut(Qt::CTRL + Qt::Key_H);
	HelpMenu->addAction(HelpInfo);
	connect(HelpInfo, SIGNAL(triggered()), this, SLOT(HelpInfoManagement()));

	ToolBar->addAction(FileLoad);
	ToolBar->addAction(HelpInfo);
}

myCppDoc::~myCppDoc()
{}
