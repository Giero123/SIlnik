#ifndef DRAWPRIMITIVES_H
#define DRAWPRIMITIVES_H
#include "Engine.h"

class DrawPrimitives
{
public:
	void DrawLine(int x, int y, int size);
	void DrawMultiLine(int x1, int y1, int x2, int y2, int size);
	void DrawCircle(int r, int filled, int size);
	void DrawRectangle(int x1, int y1, int x2, int y2, int filled, int size);
	void DrawTriangle(int x1, int y1, int x2, int y2, int filled, int size);
};



#endif