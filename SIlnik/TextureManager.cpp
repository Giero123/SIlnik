#include "TextureManager.h"
#include "Engine.h"
#include <string>
#include <iostream>

TextureManager* TextureManager::s_Instance = nullptr;

bool TextureManager::Load(std::string id, std::string filename)
{
	SDL_Surface* surface = IMG_Load(filename.c_str());
		if (surface == nullptr)
		{
			std::cout << "Fail: wczytanie powierzchni : " << filename << " z bledem : " << SDL_GetError() << std::endl;
			return false;
		}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), surface);
	if(texture == nullptr)
	{
		std::cout << "Fail: wczytanie tekstury : " << filename << " z bledem : " << SDL_GetError() << std::endl;
		return false;
	}

	textureMap[id] = texture;
	return true;

}

void TextureManager::Drop(std::string id)
{
}

void TextureManager::Clean()
{
}

void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), textureMap[id], &srcRect, &destRect, 0, 0, flip);
}
