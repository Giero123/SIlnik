#include "DrawPrimitives.h"
#include <cmath>;
#include "Engine.h"

void DrawPrimitives::DrawLine(int x1, int y1,int x2,int y2)
{
	if(y1>y2)
	{
		int tmp;
		tmp = y1;
		y1 = y2;
		y2 = y1;
	}
	if (x1 > x2)
	{
		int tmp;
		tmp = x1;
		x1 = x2;
		x2 = x1;
	}

	//sprawdzanie orietacji
	float dx = x2 - x1;
	float dy = y2 - y1;

	float length = sqrt(dx * dx + dy * dy);
	
	if(dx>=dy){
	for(int x=x1;x<x2;x++)
		{
		int y = y1 + dy * (x - x1) / dx;
		x = (int)round(x);
		y = (int)round(y);
		SDL_SetRenderDrawColor(Engine::GetInstance()->Renderer, 255, 255, 255, 255);
		SDL_RenderDrawPoint(Engine::GetInstance()->Renderer, x, y);
		SDL_RenderPresent(Engine::GetInstance()->Renderer);
		}
	}
	else
	{
		for (int y = y1; y < x2; y++)
		{
			int x = y1 + dy * (y - x1) / dx;
		}
	}
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


