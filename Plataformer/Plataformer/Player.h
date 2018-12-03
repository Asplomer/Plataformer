#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

#include <SFML\Graphics.hpp>
#include <STP\TMXLoader.hpp>

#include "Manager.h"
#include "AuxBB.h"

namespace Plataformer {
	using namespace sf;
	class Player{
	private:
		const float PLAYERSPEED = 1.2f;
		Sprite _playerSprite;
		BoundingBox _boxPlayer;
		float _momentum;
		bool _jump;
		bool _direction;
		bool _atacking;
		float _atackCooldown;
		bool _atackCD;
		float _atackStart;
		Sprite _atackSprite;
		//BoundingBox _boxAtack;
	public:
		void InitPlayer(BoundingBox box);
		bool UpdatePlayer(float aux1, float aux2);		//devuelve si esta atacando
		void DrawPlayer();
		void InputPlayer();
		void UnloadPlayer();
		bool OnGroundPlayer();
		bool PlayerJump(bool colision);
		BoundingBox BoundingAtack();
		float AngleToPlayer(BoundingBox from);
		BoundingBox BoundingPlayer();
	};
}
#endif