#include "drawArea.h"

#include <QPainter>
#include <QOpenGLFunctions>

drawArea::drawArea(QWidget *parent, const set<Block>& setOfBlocks)
	: QOpenGLWidget(parent), blocks(setOfBlocks) {
}

void drawArea::initializeGL() {
}

void drawArea::resizeGL(int width, int height) {
}

void drawArea::paintGL() {
	QPainter paint(this);
	paint.setPen(Qt::black);
	QString qs("Hello");
	paint.drawText(100, 100, qs);
}
