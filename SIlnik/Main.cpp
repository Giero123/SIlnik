#include "Engine.h"
#include "DrawPrimitives.h"

int main(int argc, char* args[])
{
    Engine::GetInstance()->Init();

    //MainLoop
    while (Engine::GetInstance()->IsRunning())
    {
        Engine::GetInstance()->Events();
        Engine::GetInstance()->Update();
        Engine::GetInstance()->Render();
        DrawPrimitives::GetInstance()->DrawCircle(2, 1, 1);
    }

    Engine::GetInstance()->Clean();

    return 0;
}