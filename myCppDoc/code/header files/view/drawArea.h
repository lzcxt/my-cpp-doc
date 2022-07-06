#pragma once

#include "common.h"
#include <QOpenGLWidget>

#include<set>
using namespace std;

struct PointXY
{
	int x;
	int y;
	int w;
	int h;
};

class drawArea : public QOpenGLWidget {
	Q_OBJECT
public:
	drawArea(QWidget* parent, const set<Block>& setOfBlocks);
	void setBlockVisual(const string& BlockName, const bool& nvisual);
protected:
	void mouseMoveEvent(QMouseEvent* event);
	void wheelEvent(QWheelEvent* event);

	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();
private:
	const static int base_width;
	const static int base_height;
	int zoom;
	set<Block> blocks;
	vector<struct PointXY> rectangle;
};