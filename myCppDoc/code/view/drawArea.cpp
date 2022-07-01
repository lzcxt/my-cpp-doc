#include "drawArea.h"

#include <QPainter>

drawArea::drawArea(QWidget *parent, const set<Block>& setOfBlocks)
	: QOpenGLWidget(parent), blocks(setOfBlocks) {
}

void drawArea::initializeGL() {

}

void drawArea::resizeGL(int width, int height) {

}

void drawArea::paintGL() {
	QPainter paint;
	paint.setPen(Qt::white);
	paint.drawLine(0, 0, 100, 100);
}
