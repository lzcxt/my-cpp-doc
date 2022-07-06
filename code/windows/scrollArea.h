#pragma once
#include <QScrollArea>

class scrollArea : public QScrollArea {
protected:
	void wheelEvent(QWheelEvent* event);
public:
	scrollArea(QWidget* w);
};