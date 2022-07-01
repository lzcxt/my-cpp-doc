#include "drawArea.h"

#include <vector>
#include <QPainter>

//some used only in this file
struct PointXY
{
	int x;
	int y;
};

vector<PointXY> paint_strategy(const set<Block> &blocks, QPainter &painter);

drawArea::drawArea(QWidget *parent, const set<Block>& setOfBlocks)
	: QOpenGLWidget(parent), blocks(setOfBlocks) {
}

void drawArea::initializeGL() {
	
}

void drawArea::resizeGL(int width, int height) {

}

void drawArea::paintGL() {
	
	//test case
	blocks.clear();//set empty
	Class a,b,c;
	


	//initialize
	QPainter paint(this);
	QFont font;
	vector<PointXY> strategy = paint_strategy(blocks, paint);
	vector<PointXY>::iterator s = strategy.begin();
	set<Block>::iterator b = blocks.begin();

	//Paint the blocks
	paint.setPen(Qt::white); 	
	while(b!=blocks.end()&&s!=strategy.end())
	{
		//Paint the Rectangle

		paint.drawRect(s->x,s->y,b->getWidth(), b->getHeight());
		//Text the names
		font.setFamily("Microsoft YaHei");
		font.setPointSize(50);
		font.setItalic(true);
		paint.setFont(font);
		QString tmp_name(b->getThisClass().getName().c_str());
		paint.drawText(100,100,tmp_name);
		//Text the attributes
		font.setFamily("Microsoft YaHei");
		font.setPointSize(40);
		font.setItalic(false);
		paint.setFont(font);
		vector<string>::iterator a = b->getThisClass().getAttributes().begin();
		for (; a != b->getThisClass().getAttributes().end(); a++)
		{
			QString tmp_attribute(a->c_str());
			paint.drawText(0, 0, tmp_attribute);
		}
		//next one
		b++; s++;
	}

	//Paint the relations
	paint.setPen(Qt::black);
	
	//0 inherit

	//1 include
	
	
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
		tmp = {width_intervel,max_height};
		p.push_back(tmp);
		tmp = { 2*width_intervel + width,max_height };
		p.push_back(tmp);
		b++;
		width+= b->getWidth();
		height = height > b->getHeight() ? height : b->getHeight();
		max_width = max_width > width ? max_width : width;
		max_height += (height + height_intervel);
	}
	max_width += 3*width_intervel;
	painter.setWindow(0,0,max_width,max_height);
	return p;
	//the optimized strategy
}