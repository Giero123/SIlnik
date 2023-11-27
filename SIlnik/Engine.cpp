#include "Engine.h"
#include <iostream>
#include "DrawPrimitives.h"
#include "TextureManager.h"

Engine* Engine::s_Instance = nullptr;
#define CHARACTER_NUM_FRAMES 8
#define CHARACTER_FRAME_WIDTH 40
#define CHARACTER_FRAME_HEIGHT 50
#define CHARACTER_FRAME_DELAY 8
#define CHARACTER_SPEED 4

bool Engine::Init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0 && SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Failed to initialize SDL %s", SDL_GetError());
        return false;
    }

    Window = SDL_CreateWindow("Silnik_GGG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ScreenWidth, ScreenHeight, 0);
    if (Window == nullptr)
    {
        SDL_Log("Failed to create window %s", SDL_GetError());
        return false;
    }

    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (Renderer == nullptr)
    {
        SDL_Log("Failed to create renderer %s", SDL_GetError());
        return false;
    }

    // Inicjalizuj t³o
    if (!InitBackground())
    {
        return false;
    }

    // Inicjalizuj animacjê postaci
    if (!InitCharacterAnimation())
    {
        return false;
    }

    if (!InitMoneySpinner())
    {
        return false;
    }

    Draw();

    return isRunning = true;
}

bool Engine::Clean()
{
	return true;
}

bool Engine::InitBackground()
{
	// Za³aduj t³o tylko raz
	backgroundTexture = TextureManager::GetInstance()->Load("Background", "assets/Background.png");
	if (backgroundTexture == nullptr)
	{
		SDL_Log("Failed to load background texture");
		return false;
	}

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

void Engine::UpdateCharacterAnimation()
{
    characterFrame += 1;
    if (characterFrame >= CHARACTER_NUM_FRAMES * CHARACTER_FRAME_DELAY)
    {
        characterFrame = 0;
    }

    if (moveLeft)
    {
        characterDestRect.x -= characterSpeed;
        characterFlip= SDL_FLIP_HORIZONTAL;
    }
    if (moveRight)
    {
        characterDestRect.x += characterSpeed;
        characterFlip = SDL_FLIP_NONE;
    }
    if (moveUp)
    {
        characterDestRect.y -= characterSpeed;
    }
    if (moveDown)
    {
        characterDestRect.y += characterSpeed;
    }

    characterSrcRect.x = (characterFrame / CHARACTER_FRAME_DELAY) * CHARACTER_FRAME_WIDTH;
}

bool Engine::InitMoneySpinner()
{
    moneyTexture = TextureManager::GetInstance()->Load("Money", "assets/money.jpg");

    if (moneyTexture == nullptr)
    {
        SDL_Log("Nie udalo sie wczytac tekstury pieniadza");
        return false;
    }

    moneySrcRect.w = 80;
    moneySrcRect.h = 33;
    moneySrcRect.x = 0;
    moneySrcRect.y = 0;

    moneyDestRect.w = 80;
    moneyDestRect.h = 33;
    moneyDestRect.x = 300;
    moneyDestRect.y = 100;
    return true;
}

// Inicjalizacja animacji postaci
bool Engine::InitCharacterAnimation()
{
    characterTexture = TextureManager::GetInstance()->Load("CharacterAnimation", "assets/sonic.png");
    if (characterTexture == nullptr)
    {
        SDL_Log("Nie udalo sie wczytac animacji");
        return false;
    }

    characterSrcRect.x = 10;
    characterSrcRect.y = 100;
    
    characterSrcRect.w = CHARACTER_FRAME_WIDTH;
    characterSrcRect.h = CHARACTER_FRAME_HEIGHT;

    characterDestRect.x = ScreenWidth / 2;
    characterDestRect.y = ScreenHeight / 2;
    characterDestRect.w = CHARACTER_FRAME_WIDTH;
    characterDestRect.h = CHARACTER_FRAME_HEIGHT;

    characterSpeed = CHARACTER_SPEED;
    characterFrame = 0;

    moveLeft = moveRight = moveUp = moveDown = false;

    return true;
}


bool Engine::MoneyColission()
{
    if (characterDestRect.x < 380 && characterDestRect.x > 260 && characterDestRect.y < 160 && characterDestRect.y > 20)
    { 
        return true; 
    }
    else
    {
        return false;
    }
    
}


void Engine::Update()
{
    UpdateCharacterAnimation();
    MoneyColission();
}

void Engine::Render()
{
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
    SDL_RenderClear(Renderer);

    // Rysuj t³o
    Draw();

    SDL_SetRenderDrawBlendMode(Renderer, SDL_BLENDMODE_BLEND);


    // Rysuj animacjê postaci
    SDL_RenderCopyEx(Renderer, characterTexture, &characterSrcRect, &characterDestRect,0.0,nullptr,characterFlip);
    if(!MoneyColission()){
         SDL_RenderCopyEx(Renderer, moneyTexture, &moneySrcRect, &moneyDestRect, moneyRotator, nullptr, SDL_FLIP_NONE);
        if (moneyRotator < 179.0) {
            moneyRotator++;
        } else {
            moneyRotator = 0.0;
        }
    }
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
        switch (event.key.keysym.sym)
        {
        case SDLK_LEFT:
            if (idlePosition == 1) {
                idlePosition = 0;
                characterSrcRect.y = 50;
            }
            moveLeft = true;
            leftKeyPressed = true;
            std::cout << "Lewy przycisk wcisniety\n";
            std::cout << characterSrcRect.y <<"\n";
            break;
        case SDLK_RIGHT:
            if (idlePosition == 1) {
                idlePosition = 0;
                characterSrcRect.y = 50;
            }
            moveRight = true;
            rightKeyPressed = true;
            std::cout << "Prawy przycisk wcisniety\n";
            break;
        case SDLK_UP:
            if (idlePosition == 1) {
                idlePosition = 0;
                characterSrcRect.y = 50;
            }
            moveUp = true;
            upKeyPressed = true;
            std::cout << "Gora przycisk wcisniety\n";
            break;
        case SDLK_DOWN:
            if (idlePosition == 1) {
                idlePosition = 0;
                characterSrcRect.y = 50;
            }
            moveDown = true;
            downKeyPressed = true;
            std::cout << "Dol przycisk wcisniety\n";
            break;
        default:
            break;
        }
        break;
    case SDL_KEYUP:
        switch (event.key.keysym.sym)
        {
        case SDLK_LEFT:
            leftKeyPressed = false;
            if (idlePosition == 0 && upKeyPressed == 0 && rightKeyPressed == 0 && downKeyPressed == 0) {
                idlePosition = 1;
                characterSrcRect.y = 100;
            }
            moveLeft = false;
            std::cout << "Lewy przycisk puszczony\n";
            break;
        case SDLK_RIGHT:
            rightKeyPressed = false;
            if (idlePosition == 0 && upKeyPressed == 0 && leftKeyPressed == 0 && downKeyPressed == 0) {
                idlePosition = 1;
                characterSrcRect.y = 100;
            }
            moveRight = false;
            std::cout << "Prawy przycisk puszczony\n";
            break;
        case SDLK_UP:
            upKeyPressed = false;
            if (idlePosition == 0 && leftKeyPressed == 0 && rightKeyPressed == 0 && downKeyPressed == 0) {
                idlePosition = 1;
                characterSrcRect.y = 100;
            }
            moveUp = false;
            std::cout << "Gora przycisk puszczony\n";
            break;
        case SDLK_DOWN:
            downKeyPressed = false;
            if (idlePosition == 0 && upKeyPressed == 0 && rightKeyPressed == 0 && leftKeyPressed == 0) {
                idlePosition = 1;
                characterSrcRect.y = 100;
            }
            moveDown = false;
            std::cout << "Dol przycisk puszczony\n";
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}




void Engine::Draw()
{
	TextureManager::GetInstance()->Draw("Background", 0, 0, 1440, 800);
	//DrawPrimitives::GetInstance()->DrawRectangle(ScreenWidth / 2 + 150, ScreenHeight / 2 + 150, 100, 150, 1);
}



bool Engine::IsRunning()
{
	return isRunning;
}
