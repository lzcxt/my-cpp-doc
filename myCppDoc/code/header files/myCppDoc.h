#pragma once

#include "drawArea.h"

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

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
	QAction* HelpInfo;

public slots:
	bool FileLoadManagement();
	bool HelpInfoManagement();
};
