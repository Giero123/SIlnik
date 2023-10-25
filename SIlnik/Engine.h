#ifndef ENGINE_H
#define ENGINE_H
#include "SDL.h"
#include "SDL_image.h"
#include "DrawPrimitives.h"

#define ScreenWidth 960
#define ScreenHeight 640


class Engine
{
public:

	static Engine* GetInstance()
	{
		return s_Instance = (s_Instance != nullptr) ? s_Instance : new Engine();
	}

	bool Init();
	bool Clean();

	void Quit();
	void Update();
	void Render();
	void Events();

	bool IsRunning();
	inline SDL_Renderer* GetRenderer() { return Renderer; }

	SDL_Renderer* Renderer;
	SDL_Window* Window;

private:
	Engine(){}
	bool isRunning=true;
	static Engine* s_Instance;
};

#endif //ENGINE_H
