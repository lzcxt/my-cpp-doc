#pragma once

#include "QOpenGLWidget"

class drawArea : public QOpenGLWidget {
	Q_OBJECT
public:
	drawArea(QWidget* parent);
protected:
	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();
private:
};