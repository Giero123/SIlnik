#include "DrawPrimitives.h"
#include <cmath>
#include "Engine.h"


DrawPrimitives* DrawPrimitives::s_Instance = nullptr;

void DrawPrimitives::DrawLine(int x1, int y1, int x2, int y2)
{
    /*
    Uint32 frameStart = SDL_GetTicks();
    SDL_RenderClear(Engine::GetInstance()->Renderer);
    SDL_RenderPresent(Engine::GetInstance()->Renderer);
    Uint32 frameTime = SDL_GetTicks() - frameStart;
    Uint32 frameDelay = 1000 / 60;
    if (frameDelay > frameTime) {
        SDL_Delay(frameDelay - frameTime);
        SDL_Log("FrameDelay %d", frameDelay - frameTime);
    }
    */
}


void DrawPrimitives::DrawRectangle(int x1, int y1, int a, int b,bool filled)
{
    
    DrawLine(x1-a/2,y1+b/2,x1+a/2,y1+b/2);
    DrawLine(x1-a/2,y1-b/2,x1+a/2,y1-b/2);
    DrawLine(x1+a/2,y1+b/2,x1+a/2,y1-b/2);
    DrawLine(x1-a/2,y1+b/2,x1-a/2,y1-b/2);
    if(filled==1)
    {
        for (int i = y1 - b / 2; i < y1 + b / 2; i++)
            DrawLine(x1 - a / 2, i, x1 + a / 2, i);
    }
}

void DrawPrimitives::DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, bool filled)
{
    DrawLine(x1, y1, x2, y2);
    DrawLine(x1, y1, x3, y3);
    DrawLine(x2, y2, x3, y3);
}

void DrawPrimitives::DrawCircle(int xc, int yc, int r, bool filled)
{
    SDL_SetRenderDrawColor(Engine::GetInstance()->Renderer, 255, 255, 255, 255);
    float a, step;
    int x, y;
    step = 1.0 / r;
    for(a=0;a<2*M_PI;a+=step)
    {
        x = xc + r * cos(a) + 0.5;
        y = yc + r * sin(a) + 0.5;
        SDL_RenderDrawPoint(Engine::GetInstance()->Renderer, x, y);
    }
    SDL_RenderPresent(Engine::GetInstance()->Renderer);
}