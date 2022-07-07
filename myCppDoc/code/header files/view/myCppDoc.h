#pragma once

#include "common.h"
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
#include <QCheckBox>

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

	set<Block> Blocks;

	vector<QCheckBox*> Checks;
	vector<string> BlockNames;

	QStringList getAllFiles(const QDir& dir);

	void formSelect(const set<Block>& Blocks);
	void showGraph(const list<string>& lis);

public slots:
	bool FileLoadHovered();
	bool FileSaveAsHovered();

	bool FileLoadManagement();
	bool FileLoadFolderManagement();
	bool FileSaveAsManagement();
	bool HelpInfoManagement();

	bool StateSwitchManagement();
};