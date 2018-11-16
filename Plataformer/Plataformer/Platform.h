#ifndef PLATFORM_H
#define PLATFORM_H
#include <iostream>
#include <SFML\Graphics.hpp>
#include <STP\TMXLoader.hpp>
#include "Manager.h"
namespace Plataformer {
	using namespace sf;
	class Platform {
	private:
		float _speed;
		Vector2f _platformPos;
		Vector2f _platformSpace;
		Sprite _platfSprite;



	public:
		void InitPlatform(Vector2f vec);
		void UpdatePlatform();
		void DrawPlatform();
		void UnloadPlatform();
		bool ColisionPlatform(Vector2f min, Vector2f max);
	};
}
#endif