#include "Engine.h"
#include <iostream>
#include "DrawPrimitives.h"

Engine* Engine::s_Instance = nullptr;
DrawPrimitives* DrawPrimitives::s_Instance = nullptr;


bool Engine::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0 && SDL_Init(SDL_INIT_VIDEO) != 0) {
		SDL_Log("Failed to initialize SDL %s", SDL_GetError());
		return false;
	}
	Window = SDL_CreateWindow("Silnik_GGG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ScreenWidth, ScreenHeight, 0);
	if(Window==nullptr)
	{
		SDL_Log("Failed to create window %s", SDL_GetError());
		return false;
	}

	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(Renderer==nullptr)
	{
		SDL_Log("Failed to create renderer %s", SDL_GetError());
		return false;
	}


	DrawPrimitives::GetInstance()->DrawLine(100, 200, 90, -40);
	return isRunning = true;
}

bool Engine::Clean()
{
	return true;
}

void Engine::Quit()
{
	
}

void Engine::Update()
{
	//std::cout << "EO" << std::endl;
}

void Engine::Render()
{
	SDL_SetRenderDrawColor(Renderer, 0, 0, 0,255);
	SDL_RenderClear(Renderer);
}

void Engine::Events()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		Quit();
		break;
	case SDL_KEYDOWN:
		printf("KeyDown ");
		break;
	}
}

bool Engine::IsRunning()
{
	return isRunning;
}






