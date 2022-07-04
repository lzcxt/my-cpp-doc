#include "drawArea.h"
#include "SetFont.h"
#include <fstream>
#include <vector>
#include <QPainter>
#include <cmath>
//#include <gl/glut.h>

using namespace std;
fstream db_err_v("View_ErrorLog.txt", fstream::out);

//some used only in this file
struct PointXY
{
	int x;
	int y;
};

vector<PointXY> paint_strategy(const set<Block> &blocks, QPainter &painter);
void DrawArrow(QPainter &painter, struct PointXY sp, struct PointXY ep);

drawArea::drawArea(QWidget *parent, const set<Block>& setOfBlocks)
	: QOpenGLWidget(parent), blocks(setOfBlocks) {
}

void drawArea::initializeGL() {
	//glClearColor(1, 1, 1, 1);
}

void drawArea::resizeGL(int width, int height) {

}

void drawArea::paintGL() {

	/*
	test case:

	*/


	//initialize
	QPainter paint(this);
	paint.setPen(Qt::NoPen);
	paint.setBrush(Qt::white);
	paint.drawRect(rect());
	QFont font;
	vector<PointXY> strategy = paint_strategy(blocks, paint);
	vector<PointXY>::iterator s = strategy.begin();
	set<Block>::iterator b = blocks.begin();

	//Paint the blocks
	while (b != blocks.end() && s != strategy.end())
	{
		//Paint the Rectangle
		paint.setPen(QPen(QColor(0x7f, 0xb5, 0xa7), 0.5));
		paint.drawRect(s->x, s->y, b->getWidth(), b->getHeight());
		int tmp_x = s->x;
		int tmp_y = s->y;
		//Text the names
		SetNameFont(font);
		paint.setFont(font);
		paint.setPen(QPen(QColor(0x75, 0x75, 0x75), 0.5));
		QFontMetrics Metrics(font);
		QString tmp_name(b->getThisClass().getName().c_str());
		paint.drawText(s->x + b->getWidth() / 1.3*0.15, s->y + b->getHeight() / 1.3*0.05 + Metrics.height(), tmp_name);
		tmp_x += b->getWidth() / 1.3*0.15;
		tmp_y += b->getHeight() / 1.3*0.05 + Metrics.height();
		//Text the attributes
		SetAttributeFont(font);
		paint.setFont(font);
		paint.setPen(QPen(QColor(0x0, 0x0, 0x0), 0.5));
		vector<string> tmp_v = b->getThisClass().getAttributes();
		vector<string>::iterator a = tmp_v.begin();
		Metrics = QFontMetrics(font);
		for (; a != tmp_v.end(); a++)
		{
			tmp_y += Metrics.height() + 2;
			QString tmp_attribute(a->c_str());
			paint.drawText(tmp_x, tmp_y, tmp_attribute);
		}
		//next one
		b++; s++;

	}

	//Paint the relations
	//Paint the SuperClasses
	b = blocks.begin(); s = strategy.begin();
	while (b != blocks.end() && s != strategy.end())
	{
		vector<string> SuperClass = b->getThisClass().getSuperclasses();
		vector<string>::iterator sc = SuperClass.begin();
		db_err_v << b->getThisClass().getName() << ":" << endl;
		while (sc != SuperClass.end())
		{
			db_err_v << *sc << endl;
			vector<PointXY>::iterator s2 = strategy.begin();
			set<Block>::iterator b2 = blocks.begin();
			while (b2 != blocks.end() && s2 != strategy.end())
			{
				string tmp_name = b2->getThisClass().getName();
				if (tmp_name.compare(*sc) == 0)break;
				b2++; s2++;
			}
			paint.setPen(QPen(Qt::darkGreen, 0.3));
			struct PointXY tmp = { s2->x + b2->getWidth(),s2->y + b2->getHeight() };
			DrawArrow(paint, *s, tmp);
			sc++;
		}
		b++; s++;
	}
	//Paint the Components

}



vector<PointXY> paint_strategy(const set<Block> &blocks, QPainter &painter)
{
	vector<PointXY> p;
	//initial strategy: sequential
	//arrange the start positions of the blocks and the Window
	const int width_intervel = 10;
	const int height_intervel = 10;
	int max_width = 0;
	int max_height = height_intervel;
	set<Block>::iterator b = blocks.begin();
	for (; b != blocks.end(); b++)
	{
		struct PointXY tmp;
		int width = b->getWidth();
		int height = b->getHeight();
		tmp = { width_intervel,max_height };
		p.push_back(tmp);
		tmp = { 2 * width_intervel + width,max_height };
		p.push_back(tmp);
		b++;
		if (b == blocks.end())
		{
			max_width = max_width > width ? max_width : width;
			max_height += (height + height_intervel);
			break;
		}
		width += b->getWidth();
		height = height > b->getHeight() ? height : b->getHeight();
		max_width = max_width > width ? max_width : width;
		max_height += (height + height_intervel);
	}
	max_width += 3 * width_intervel;
	painter.setWindow(0, 0, max_width, max_height);
	return p;
	//the optimized strategy
}

void DrawArrow(QPainter &painter, struct PointXY sp, struct PointXY ep)
{
	double length = sqrt(pow(sp.x - ep.x, 2) + pow(sp.y - ep.y, 2));
	double arrow_length = min(length / 10, 2.0);
	double angle;
	double angle1;
	double angle2;
	QVector<QLineF> lines;
	lines.append(QLineF(sp.x, sp.y, ep.x, ep.y));
	if (ep.x > sp.x)
	{
		if (ep.y < sp.y)
		{
			angle = acos((ep.x - sp.x) / length);

			if (angle > 45)
			{
				angle1 = angle - 45;
				angle2 = angle + 45;
				angle2 = 180 - angle2;
				lines.append(QLineF(ep.x, ep.y, ep.x - arrow_length * cos(angle1), ep.y + arrow_length * sin(angle1)));
				lines.append(QLineF(ep.x, ep.y, ep.x + arrow_length * cos(angle2), ep.y + arrow_length * sin(angle2)));
			}
			else
			{
				angle1 = -angle + 45;
				angle2 = angle + 45;
				lines.append(QLineF(ep.x, ep.y, ep.x - arrow_length * cos(angle1), ep.y - arrow_length * sin(angle1)));
				lines.append(QLineF(ep.x, ep.y, ep.x - arrow_length * cos(angle2), ep.y + arrow_length * sin(angle2)));
			}
		}
		else
		{
			angle = acos((ep.x - sp.x) / length);
			if (angle > 45)
			{
				angle1 = angle - 45;
				angle2 = angle + 45;
				angle2 = 180 - angle2;
				lines.append(QLineF(ep.x, ep.y, ep.x - arrow_length * cos(angle1), ep.y - arrow_length * sin(angle1)));
				lines.append(QLineF(ep.x, ep.y, ep.x + arrow_length * cos(angle2), ep.y - arrow_length * sin(angle2)));
			}
			else
			{
				angle1 = -angle + 45;
				angle2 = angle + 45;
				lines.append(QLineF(ep.x, ep.y, ep.x - arrow_length * cos(angle1), ep.y + arrow_length * sin(angle1)));
				lines.append(QLineF(ep.x, ep.y, ep.x - arrow_length * cos(angle2), ep.y - arrow_length * sin(angle2)));
			}
		}
	}
	else
	{
		if (ep.y < sp.y)
		{
			angle = acos((sp.x - ep.x) / length);
			if (angle > 45)
			{
				angle1 = angle - 45;
				angle2 = angle + 45;
				angle2 = 180 - angle2;
				lines.append(QLineF(ep.x, ep.y, ep.x + arrow_length * cos(angle1), ep.y + arrow_length * sin(angle1)));
				lines.append(QLineF(ep.x, ep.y, ep.x - arrow_length * cos(angle2), ep.y + arrow_length * sin(angle2)));
			}
			else
			{
				angle1 = -angle + 45;
				angle2 = angle + 45;
				lines.append(QLineF(ep.x, ep.y, ep.x + arrow_length * cos(angle1), ep.y - arrow_length * sin(angle1)));
				lines.append(QLineF(ep.x, ep.y, ep.x + arrow_length * cos(angle2), ep.y + arrow_length * sin(angle2)));
			}
		}
		else
		{
			angle = acos((sp.x - ep.x) / length);
			if (angle > 45)
			{
				angle1 = angle - 45;
				angle2 = angle + 45;
				angle2 = 180 - angle2;
				lines.append(QLineF(ep.x, ep.y, ep.x + arrow_length * cos(angle1), ep.y - arrow_length * sin(angle1)));
				lines.append(QLineF(ep.x, ep.y, ep.x - arrow_length * cos(angle2), ep.y - arrow_length * sin(angle2)));
			}
			else
			{
				angle1 = -angle + 45;
				angle2 = angle + 45;
				lines.append(QLineF(ep.x, ep.y, ep.x + arrow_length * cos(angle1), ep.y + arrow_length * sin(angle1)));
				lines.append(QLineF(ep.x, ep.y, ep.x + arrow_length * cos(angle2), ep.y - arrow_length * sin(angle2)));
			}
		}
	}


	painter.drawLines(lines);
}