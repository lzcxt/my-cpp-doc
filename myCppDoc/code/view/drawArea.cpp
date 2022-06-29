#include "drawArea.h"

#include<QPainter>
#include <gl/glut.h>

drawArea::drawArea(QWidget *parent)
	: QOpenGLWidget(parent) {
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
