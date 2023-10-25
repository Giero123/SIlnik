#include "Engine.h"

int main(int argc, char* args[])
{
    Engine::GetInstance()->Init();

    //MainLoop
    while (Engine::GetInstance()->IsRunning())
    {
        Engine::GetInstance()->Events();
        Engine::GetInstance()->Update();
        Engine::GetInstance()->Render();
    }

    Engine::GetInstance()->Clean();

    return 0;
}