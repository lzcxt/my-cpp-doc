#pragma once

#include "common/common.h"
#include "QOpenGLWidget"

#include<set>
using namespace std;

class drawArea : public QOpenGLWidget {
	Q_OBJECT
public:
	drawArea(QWidget* parent, const set<Block>& setOfBlocks);
protected:
	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();
private:
	set<Block> blocks;
};