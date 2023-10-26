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


void DrawPrimitives::DrawRectangle(int x1, int y1, int x2, int y2)
{
    
}

void DrawPrimitives::DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    //3x draw_multi_line
}

void DrawPrimitives::DrawCircle(int r, int filled, int size)
{

}