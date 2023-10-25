#ifndef DRAWPRIMITIVES_H
#define DRAWPRIMITIVES_H
#include "SDL.h"

class DrawPrimitives
{
public:
    static DrawPrimitives* GetInstance()
    {
        return s_Instance = (s_Instance != nullptr) ? s_Instance : new DrawPrimitives();
    }

    inline SDL_Renderer* GetRenderer() { return Renderer1; }
    SDL_Renderer* Renderer1;

    void DrawLine(int x1, int y1, int x2, int y2);
    void DrawCircle(int r, int filled, int size);
    void DrawRectangle(int x1, int y1, int x2, int y2);
    void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3);

    
private:
    DrawPrimitives() {}
    static DrawPrimitives* s_Instance;
};



#endif