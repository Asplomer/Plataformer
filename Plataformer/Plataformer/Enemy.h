#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>

#include <SFML\Graphics.hpp>
#include <STP\TMXLoader.hpp>

#include "Manager.h"
#include "AuxBB.h"


namespace Plataformer {
	using namespace sf;
	class Enemy {
	private:
		const float ENEMYSPEED = 0.4f;
		const float ENEMYDISTANCE = 300.0f;
		Sprite _enemySprite;
		BoundingBox _boxEnemy;
	public:
		void InitEnemy(BoundingBox playerPos, Vector2f size);
		void UpdateEnemy(BoundingBox playerPos);
		void DrawEnemy();
		void RespawnEnemy(BoundingBox playerPos);
		BoundingBox BoundingEnemy();
	};
}
#endif