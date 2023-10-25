#include "DrawPrimitives.h"
#include <cmath>
#include "Engine.h"

DrawPrimitives* DrawPrimitives::s_Instance = nullptr;

void DrawPrimitives::DrawLine(int x1, int y1,int x2,int y2)
{

}


void DrawPrimitives::DrawRectangle(int x1, int y1, int x2, int y2, int filled,int size)
{
	//4x draw_multi_line
	/*
	 * x1y1 x2y1
	 * x2y2 x2y1
	 * x1y2 x2y2
	 * x1y1 x1y2
	 */
}

void DrawPrimitives::DrawTriangle(int x1, int y1, int x2, int y2, int filled, int size)
{
	//3x draw_multi_line
}

void DrawPrimitives::DrawCircle(int r, int filled, int size)
{
	
}


