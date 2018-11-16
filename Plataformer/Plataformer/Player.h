#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <SFML\Graphics.hpp>
#include <STP\TMXLoader.hpp>
#include "Manager.h"

namespace Plataformer {
	using namespace sf;
	class Player{
	private:
		Sprite _playerSprite;
		Vector2f _playerPos ;
		Vector2f _playerSpace;
		
		//float _speed;
		float _momentum;
		bool _jump;
	public:
		void InitPlayer(Vector2f vec);
		void UpdatePlayer();
		void DrawPlayer();
//		bool OnAirPlayer();
		bool OnGroundPlayer();
		void InputPlayer();
		void UnloadPlayer();
	
	};
}
#endif