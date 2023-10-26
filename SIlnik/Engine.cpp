#include "Engine.h"
#include <iostream>
#include "DrawPrimitives.h"
#include "TextureManager.h"
#include <SDL_framerate.h>
#include <SDL_gfxPrimitives.h>

Engine* Engine::s_Instance = nullptr;

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
	TextureManager::GetInstance()->Load("Background", "assets/Background.png");
	return isRunning = true;
}

bool Engine::Clean()
{
	return true;
}

void Engine::Quit()
{
	TextureManager::GetInstance()->Clean();
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	IMG_Quit();
	SDL_Quit();
}

void Engine::Update()
{

}

void Engine::Render()
{
	SDL_SetRenderDrawColor(Renderer, 0, 0, 0,255);
	SDL_RenderClear(Renderer);
	DrawPrimitives::GetInstance()->DrawLine(1440, 800, 0, 0);
	TextureManager::GetInstance()->Draw("Background", 0, 0, 1440, 800);
	SDL_RenderPresent(Renderer);
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






