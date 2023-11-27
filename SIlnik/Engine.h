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
	bool InitBackground();
	void UpdateCharacterAnimation();
	bool InitCharacterAnimation();
	inline SDL_Renderer* GetRenderer() { return Renderer; }
	bool InitMoneySpinner();
	bool MoneyColission();

	SDL_Renderer* Renderer;
private:
	Engine() {}
	static Engine* s_Instance;
	bool isRunning = true;
	SDL_Window* Window;
	SDL_Texture* backgroundTexture;
	SDL_RendererFlip characterFlip;
	bool idlePosition = true;
	bool rightKeyPressed = false;
	bool leftKeyPressed = false;
	bool upKeyPressed = false;
	bool downKeyPressed = false;
	SDL_Texture* characterTexture; // tekstura animacji postaci
	SDL_Texture* moneyTexture;
	SDL_Rect characterSrcRect;  // prostok¹t Ÿród³owy dla animacji postaci
	SDL_Rect characterDestRect; // prostok¹t docelowy dla animacji postaci
	SDL_Rect moneySrcRect;
	SDL_Rect moneyDestRect;
	float moneyRotator = 0.0;
	int characterSpeed;          // prêdkoœæ animacji postaci
	int characterFrame;          // aktualna klatka animacji postaci
	bool moveLeft, moveRight, moveUp, moveDown; // flagi ruchu w odpowiednich kierunkach
};

#endif //ENGINE_H