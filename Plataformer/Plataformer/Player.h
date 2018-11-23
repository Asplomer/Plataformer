#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <SFML\Graphics.hpp>
#include <STP\TMXLoader.hpp>
#include "Manager.h"
#include "AuxBB.h"

#define PLAYERSPEED 1.2f
namespace Plataformer {
	using namespace sf;
	class Player{
	private:
		Sprite _playerSprite;
		BoundingBox _boxPlayer;
		float _momentum;
		bool _jump;
	public:
		void InitPlayer(BoundingBox box);
		void UpdatePlayer(float aux1, float aux2);
		void DrawPlayer();
		bool OnGroundPlayer();
		void InputPlayer();
		void UnloadPlayer();
		bool PlayerJump(bool colision);
		BoundingBox BoundingPlayer();
	};
}
#endif