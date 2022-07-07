#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../common/common.h"
#include "../view/drawArea.h"
#include "../view/translator.h"
#include "../view_model/parser.h"
#include "../view/viewCmFunctions.h"
#include "../view_model/parser.h"

#include <memory>
#include <QFileDialog>
#include <QString>
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
#include <QScrollArea>

using namespace std;

class mainWindow : public QMainWindow {
    Q_OBJECT
public:
    mainWindow(QWidget *parent = nullptr);
    ~mainWindow() {}
    void attach_fileProcessor(fileProcessor && fp) {
        m_file_processor = std::move(fp);
    }

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

    fileProcessor m_file_processor;

    QStringList getAllFiles(const QDir& dir);
    void formSelect(const set<Block>& Blocks);
    void showGraph(const list<string>& filelist);
    void signalReadFinished() {};
    void signalParse() {};

private slots:
    bool FileLoadHovered();
    bool FileSaveAsHovered();

    bool FileLoadManagement();
    bool FileLoadFolderManagement();
    bool FileSaveAsManagement();
    bool HelpInfoManagement();

    bool StateSwitchManagement();
};

class scrollArea : public QScrollArea {
protected:
    void wheelEvent(QWheelEvent* event) { }
public:
    scrollArea(QWidget* w) : QScrollArea(w) { }
};

#endif // MAINWINDOW_H
