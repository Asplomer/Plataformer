#ifndef START_H
#define START_H

#include <iostream>

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <STP\TMXLoader.hpp>

#include "Manager.h"
using namespace std;
namespace Plataformer {
	const int TEXTNUMBERSTART = 5;

	void InitStart();
	void UpdateStart();
	void DrawStart();
};
#endif