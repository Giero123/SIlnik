#ifndef ENGINE_H
#define ENGINE_H
#include "SDL.h"
#include "SDL_image.h"
#include "DrawPrimitives.h"

#define ScreenWidth 1440
#define ScreenHeight 800


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
	void Draw();
	bool IsRunning();
	inline SDL_Renderer* GetRenderer() { return Renderer; }

	
	SDL_Renderer* Renderer;
private:
	Engine(){}
	static Engine* s_Instance;
	bool isRunning = true;
	SDL_Window* Window;
	
	
};

#endif //ENGINE_H
