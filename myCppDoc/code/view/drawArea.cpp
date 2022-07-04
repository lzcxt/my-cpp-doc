#include "drawArea.h"
#include "SetFont.h"
#include <fstream>
#include <vector>
#include <QPainter>
#include <cmath>

using namespace std;
fstream db_err_v("View_ErrorLog.txt", fstream::out);

#include <QPainter>

drawArea::drawArea(QWidget *parent, const set<Block>& setOfBlocks)
	: QOpenGLWidget(parent), blocks(setOfBlocks) {
}

void drawArea::initializeGL() {
}

void drawArea::resizeGL(int width, int height) {
}

void drawArea::paintGL() {
	QPainter paint(this);
	paint.setPen(Qt::white);
	paint.drawLine(0, 0, 100, 100);
}
