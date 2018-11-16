#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <SFML\Graphics.hpp>
#include <STP\TMXLoader.hpp>
using namespace sf;
using namespace std;
#define PLAYERSPEED 10.0f
namespace Plataformer{
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
		void UpdatePlayer();
};
#endif

