#ifndef START_H
#define START_H
#include "Manager.h"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <STP\TMXLoader.hpp>
#include <iostream>
#define TEXTNUMBERSTART 5
using namespace std;
namespace Plataformer {

	void InitStart();
	void UpdateStart();
	void DrawStart();
};
#endif