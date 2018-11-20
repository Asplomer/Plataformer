#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <SFML\Graphics.hpp>
#include <STP\TMXLoader.hpp>
#include "Platform.h"
#include "Player.h"

using namespace std;
#define PLAYERSPEED 10.0f
namespace Plataformer{
	using namespace sf;
	extern int screenWidth;
	extern int screenHeight;
	extern int verMajor;
	extern int verMinor;
	enum PlayState
	{
		Start,
		Play,
		GameOver,
		Credit,
		End
	};
	extern RenderWindow* window;
	void InitManager();
	void UpdateManager(float time);
	void DrawManager();
	bool ColiderManager(Vector2f vec1, Vector2f vec2);
};
#endif

