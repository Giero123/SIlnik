#include "DrawPrimitives.h"
#include <cmath>
#include "Engine.h"
#include "SDL_image.h"

void DrawPrimitives::DrawLine(int x1, int y1,int x2,int y2)
{
	SDL_SetRenderDrawColor(Engine::GetInstance()->Renderer, 255, 255, 255, 255);
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx, sy;

	if (x1 < x2)
		sx = 1;
	else
		sx = -1;
	if (y1 < y2)
		sy = 1;
	else
		sy = -1;
	int err = dx - dy;

	int x = x1;
	int y = y1;
	while(true)
	{
		SDL_RenderDrawPoint(Engine::GetInstance()->Renderer, x, y);
		if(x==x2 && y==y2)
		{
			break;
		}
		int e2 = 2 * err;
		if(e2>-dy)
		{
			err -= dy;
			x += sx;
		}
		if(e2<dx)
		{
			err += dx;
			y += sy;
		}
	}
	SDL_RenderPresent(Engine::GetInstance()->Renderer);
}


void DrawPrimitives::DrawRectangle(int x, int y, int width, int filled, int size)
{
	//4x draw_multi_line
	/*
	 *
	 *
	 *
	 */
}

void DrawPrimitives::DrawTriangle(int x1, int y1, int x2, int y2, int filled, int size)
{
	//3x draw_multi_line
}

void DrawPrimitives::DrawCircle(int r, int filled, int size)
{
	
}


