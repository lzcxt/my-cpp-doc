#pragma once

#include "drawArea.h"

#include <QDir>
#include <QVariant>
#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QWidget>
#include <QLabel>
#include <QScrollArea>

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
	QAction* FileSaveAs;
	QAction* HelpInfo;

	QStatusBar* Status;

	QScrollArea* scroll;
	drawArea* draw;

	QStringList getAllFiles(const QDir& dir);

protected:
	void mouseMoveEvent();

public slots:
	bool FileLoadHovered();
	bool FileSaveAsHovered();

	bool FileLoadManagement();
	bool FileLoadFolderManagement();
	bool FileSaveAsManagement();
	bool HelpInfoManagement();
};
