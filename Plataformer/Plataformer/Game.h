#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "Manager.h"
#include "AuxBB.h"

using namespace std;
namespace Plataformer {


		void InitGame();
		bool DetectCol(BoundingBox rect1, BoundingBox rect2);
		void UpdateGame();
		void DrawGame();

}
#endif
