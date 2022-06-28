/********************************************************************************
** Form generated from reading UI file 'myCppDoc.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCPPDOC_H
#define UI_MYCPPDOC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myCppDocClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *myCppDocClass)
    {
        if (myCppDocClass->objectName().isEmpty())
            myCppDocClass->setObjectName(QString::fromUtf8("myCppDocClass"));
        myCppDocClass->resize(600, 400);
        menuBar = new QMenuBar(myCppDocClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        myCppDocClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(myCppDocClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        myCppDocClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(myCppDocClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        myCppDocClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(myCppDocClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        myCppDocClass->setStatusBar(statusBar);

        retranslateUi(myCppDocClass);

        QMetaObject::connectSlotsByName(myCppDocClass);
    } // setupUi

    void retranslateUi(QMainWindow *myCppDocClass)
    {
        myCppDocClass->setWindowTitle(QApplication::translate("myCppDocClass", "myCppDoc", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myCppDocClass: public Ui_myCppDocClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCPPDOC_H
