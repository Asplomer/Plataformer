#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML\Graphics.hpp>
#include <STP\TMXLoader.hpp>
#include "Manager.h"
namespace Plataformer {
	class Platform {
	private:
		float speed;
	public:
		void InitPlatform();
		void UpdatePlatform();
		void DrawPlatform();
		void UnloadPlatform();

	};
}
#endif