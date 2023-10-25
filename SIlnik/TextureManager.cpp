#include "TextureManager.h"
#include <string>
#include "Engine.h"

bool TextureManager::Load(std::string id, std::string filename)
{
	SDL_Surface* surface = IMG_Load(filename.c_str());
	if (surface == nullptr)
	{
		SDL_Log("Nie udalo sie wczytac powierzchni: %s", SDL_GetError());
		return false;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), surface);
	if (texture == nullptr)
	{
		SDL_Log("Nie udalo sie stworzyc tektury: %s", SDL_GetError());
		return false;
	}
	SDL_FreeSurface(surface);
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
}
