#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <cmath>

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <STP\TMXLoader.hpp>
#include <SFML\Audio.hpp>

#include "Start.h"
#include "Game.h"
#include "Credits.h"
#include "Platform.h"
#include "Player.h"

#include "Enemy.h"
#include "AuxBB.h"

using namespace std;
using namespace sf;

namespace Plataformer {
	const int PLATFORMARRAYSIZE = 4;
	extern int screenWidth;
	extern int screenHeight;
	extern String verMajor;
	extern String verMinor;
	extern int gameState;
	extern float hourglass;
	extern float time;
	extern Font font;
	extern Text text;
	extern RenderWindow* window;
	enum PlayState
	{
		Start,
		Play,
		GameOver,
		Credit,
		End
	};
	void PlayTheGame();
	void InitManager();
	void UpdateManager();
	void DrawManager();
};
#endif

