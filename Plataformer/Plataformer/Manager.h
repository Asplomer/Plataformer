#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <STP\TMXLoader.hpp>
#include "Start.h"
#include "Game.h"
#include "Credits.h"
#include "Platform.h"
#include "Player.h"

#include "Enemy.h"
#include "AuxBB.h"

#include <cmath>
using namespace std;
using namespace sf;
#define PLATFORMARRAYSIZE 4

namespace Plataformer {
	
	extern int screenWidth;
	extern int screenHeight;
	extern String verMajor;
	extern String verMinor;
	extern int gameState;
	extern float hourglass;
	extern float time;
	extern Font font;
	extern Text text;
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

