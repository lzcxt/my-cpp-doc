#include "myCppDoc.h"
#include <QMessageBox>
#include <QFileDialog>

#include <gl/glut.h>

bool myCppDoc::FileLoadManagement() {
	QStringList path = QFileDialog::getOpenFileNames();
	//TODO
	return 1;
}

bool myCppDoc::HelpInfoManagement() {
	//TODO
	return 1;
}