#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_myCppDoc.h"

class myCppDoc : public QMainWindow
{
    Q_OBJECT

public:
    myCppDoc(QWidget *parent = nullptr);
    ~myCppDoc();

private:
    Ui::myCppDocClass ui;

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
