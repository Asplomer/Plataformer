#include "Enemy.h"
namespace Plataformer {
	static Texture _enemyTexture;
	void Enemy::InitEnemy(BoundingBox playerPos) {
		float aux = rand() %360; //devuelve un valore entre 0 y 359
		float posX = ENEMYDISTANCE * cosf(aux);
		float posY = ENEMYDISTANCE * sinf(aux);
		_boxEnemy.x = playerPos.x + posX;
		_boxEnemy.y = playerPos.y + posY;
		//_boxEnemy.x = playerPos.x + ENEMYDISTANCE;
		//_boxEnemy.y = playerPos.y + ENEMYDISTANCE;
		if(_enemyTexture.loadFromFile("res/EvilEye.png")){
			//you done goofed
		}
		_enemySprite.setPosition(_boxEnemy.x, _boxEnemy.y);
	}
	void Enemy::UpdateEnemy(BoundingBox playerPos){
		float angle = atan2(playerPos.y - _boxEnemy.y, playerPos.x - _boxEnemy.x);
		_boxEnemy.x += cosf(angle) * ENEMYSPEED * time * 100;
		_boxEnemy.y += sinf(angle)*ENEMYSPEED*time * 100;
	}
	void Enemy::DrawEnemy(){
		_enemySprite.setPosition(_boxEnemy.x, _boxEnemy.y);
		_enemySprite.setTexture(_enemyTexture);
		window->draw(_enemySprite);
	}
	void Enemy::RespawnEnemy(BoundingBox playerPos) {
		float aux = rand() % 360; //devuelve un valore entre 0 y 359
		float posX = ENEMYDISTANCE * cosf(aux);
		float posY = ENEMYDISTANCE * sinf(aux);
		_boxEnemy.x = playerPos.x + posX;
		_boxEnemy.y = playerPos.y + posY;
		_enemySprite.setPosition(_boxEnemy.x, _boxEnemy.y);

	}
	BoundingBox Enemy::BoundingEnemy(){
		return _boxEnemy;
	}





}