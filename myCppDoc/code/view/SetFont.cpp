#include "SetFont.h"
void SetNameFont(QFont &font)
{
	font.setFamily("Microsoft YaHei");
	font.setUnderline(true);
	font.setPointSize(10);
	font.setItalic(true);
}
void SetAttributeFont(QFont &font)
{
	font.setFamily("Microsoft YaHei");
	font.setUnderline(false);
	font.setPointSize(8);
	font.setItalic(false);
}