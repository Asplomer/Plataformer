#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <SFML\Graphics.hpp>
#include <STP\TMXLoader.hpp>
#include "Manager.h"
#include "AuxBB.h"
#define ENEMYSPEED 0.4f
#define ENEMYDISTANCE 300.0f
namespace Plataformer {
	using namespace sf;
	class Enemy {
	private:
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