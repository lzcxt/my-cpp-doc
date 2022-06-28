#include "myCppDoc.h"
#include <QMessageBox>
#include <QFileDialog>

#include <gl/glut.h>

bool myCppDoc::FileLoadManagement() {
	QStringList path = QFileDialog::getOpenFileNames();
	return 1;
}

bool myCppDoc::HelpInfoManagement() {

	return 1;
}