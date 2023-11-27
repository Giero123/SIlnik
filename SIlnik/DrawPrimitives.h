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

    void DrawLine(int x1, int y1, int x2, int y2);
    void DrawCircle(int xc, int yc, int r);
    void DrawRectangle(int x1, int y1, int a, int b, bool filled);
    void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3);


private:
    DrawPrimitives() {}
    static DrawPrimitives* s_Instance;
};



#endif