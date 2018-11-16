#include "Platform.h"

namespace Plataformer {
	static Texture _platf;
	void Platform::InitPlatform(Vector2f vec) {
		_speed = 0;
		_platformPos = vec;
		_platformSpace = { 128.0f, 32.0f };
		_platformPos.y += _platformSpace.y;
		if (!_platf.loadFromFile("res/Plataforma/PlatformSimple.png"))
		{
			// error...
		}
		
	}
	void Platform::UpdatePlatform() {
		//8 de ancho* alto
		_platformPos.x-=0.1f;
		_platfSprite.setPosition(_platformPos);
	}
	void Platform::DrawPlatform() {

		_platfSprite.setTexture(_platf);

		window->draw(_platfSprite);
	}
	void Platform::UnloadPlatform(){
	
	}
	bool Platform::ColisionPlatform(Vector2f min, Vector2f max) {
		if (min.y == _platformPos.y - 1)
			return true;
		return false;
	}
}