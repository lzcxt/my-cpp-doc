#pragma once

#include "drawArea.h"

#include <QVariant>
#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QWidget>
#include <QLabel>

class myCppDoc : public QMainWindow {
    Q_OBJECT

public:
    myCppDoc(QWidget *parent = nullptr);
    ~myCppDoc();

private:
	QMenuBar* MenuBar;
	QToolBar* ToolBar;

	QMenu* FileMenu;
	QMenu* OperationMenu;
	QMenu* HelpMenu;

	QAction* FileLoad;
	QAction* FileLoadFolder;
	QAction* HelpInfo;

	QStatusBar* Status;

public slots:
	bool FileLoadManagement();
	bool FileLoadFolderManagement();
	bool HelpInfoManagement();
};
