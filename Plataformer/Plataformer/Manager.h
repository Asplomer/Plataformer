#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <SFML\Graphics.hpp>
#include <STP\TMXLoader.hpp>
#include "Platform.h"
#include "Player.h"
#include "Game.h"
#include "Enemy.h"
#include "AuxBB.h"
#include <cmath>
using namespace std;
using namespace sf;
#define PLATFORMARRAYSIZE 4

namespace Plataformer {

	extern int screenWidth;
	extern int screenHeight;
	extern int verMajor;
	extern int verMinor;
	extern int gameState;
	extern float hourglass;
	extern float time;
	enum PlayState
	{
		Start,
		Play,
		GameOver,
		Credit,
		End
	};
	

	void PlayTheGame();
	extern RenderWindow* window;
	void InitManager();
	void UpdateManager();
	void DrawManager();
	
};
#endif

