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
	/*
	blocks.clear();//set empty
	Class A("A");
	Class B("B");
	Class C("C");
	Relation r1(&B, inherit);
	Relation r2(&C, inherit);
	Relation r3(&B, include);
	A.addAttributes("int x");
	A.addAttributes("int y");
	B.addRelation(r1);
	C.addRelation(r2);
	C.addRelation(r3);
	C.addAttributes("B b");
	Block b1(100,100,A);
	Block b2(50, 200, B);
	Block b3(100, 100, C);
	blocks.insert(b1);
	blocks.insert(b2);
	blocks.insert(b3);
	*/

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
		int tmp_x = s->x;
		int tmp_y = s->y;

		//Text the names
		font.setFamily("Microsoft YaHei");
		font.setPointSize(5);
		font.setItalic(true);
		paint.setFont(font);
		QString tmp_name(b->getThisClass().getName().c_str());
		paint.drawText(s->x+10,s->y+20,tmp_name);
		tmp_x += 10;
		tmp_y += 20;
		//Text the attributes
		font.setFamily("Microsoft YaHei");
		font.setPointSize(4);
		font.setItalic(false);
		paint.setFont(font);
		vector<string> tmp_v = b->getThisClass().getAttributes();
		vector<string>::iterator a = tmp_v.begin();
		for (; a != tmp_v.end(); a++)
		{
			tmp_y += 20;
			QString tmp_attribute(a->c_str());
			paint.drawText(tmp_x, tmp_y, tmp_attribute);
		}
		//next one
		b++; s++;
	}

	//Paint the relations
	
	b = blocks.begin(); s = strategy.begin();
	while (b != blocks.end() && s != strategy.end())
	{
		paint.drawLine(0, 0, 100, 100);
		/*list<Relation> tmp_r = b->getThisClass().getListOfEdges();
		list<Relation>::iterator r = tmp_r.begin();
		while (r != tmp_r.end())
		{
			Class *tmp_c = r->target;
			vector<PointXY>::iterator s2 = strategy.begin();
			set<Block>::iterator b2 = blocks.begin();
			while (b2 != blocks.end() && s2 != strategy.end())
			{
				if (b2->getThisClass().getName().compare(tmp_c->getName()))break;
				b2++; s2++;
			}
			//0 inherit
			if (r->r == inherit)
			{
				//paint.setPen(Qt::darkGreen);
				paint.setPen(Qt::white);
			}
			else//1 include
			{
				//paint.setPen(Qt::darkBlue);
				paint.setPen(Qt::white);

			}
			paint.drawLine(s->x, s->y, s2->x, s2->y);
		}*/
		b++; s++;
	}
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
		if (b == blocks.end())
		{
			max_width = max_width > width ? max_width : width;
			max_height += (height + height_intervel);
			break;
		}
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