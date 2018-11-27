#ifndef PLATFORM_H
#define PLATFORM_H
#include <iostream>
#include <SFML\Graphics.hpp>
#include <STP\TMXLoader.hpp>
#include "Manager.h"
#include "AuxBB.h"
#define PLATFORMSPEED 0.3f;
namespace Plataformer{
	using namespace sf;
	class Platform {
	private:
		float _speedx;
		float _speedy;
		Sprite _platfSprite;
		BoundingBox _boxPlatform;
		int _type1;
		int _type2;
		float _mult;
	public:
		void InitPlatform(BoundingBox box, int t1, int t2);
		void UpdatePlatform();
		void DrawPlatform();
		float ReturnMovementPlatformx();
		float ReturnMovementPlatformy();
		BoundingBox BoundingPlatform();
	};
}
#endif