#include "../app/myCppDoc.h"
using namespace std;

myCppDoc::myCppDoc() {
    m_mainWindow.attach_fileProcessor(m_parser.get_fileProcessor());
}

void myCppDoc::show() {
    m_mainWindow.show();
}
