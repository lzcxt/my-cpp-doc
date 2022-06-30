#pragma once

#include "common.h"
#include "QOpenGLWidget"

#include<set>
using namespace std;

class drawArea : public QOpenGLWidget {
	Q_OBJECT
public:
	drawArea(QWidget* parent);
protected:
	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();
private:
	set<Class> blocks;
};