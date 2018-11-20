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
	void Platform::UpdatePlatform(float time) {
		//8 de ancho* alto
		_platformPos.x-=0.01f*time;
		_platfSprite.setPosition(_platformPos);
		//cout << _platformPos.x << endl;
	}
	void Platform::DrawPlatform() {

		_platfSprite.setTexture(_platf);

		window->draw(_platfSprite);
	}
	void Platform::UnloadPlatform(){
	
	}
	bool Platform::ColisionPlatform(Vector2f min, Vector2f max) {
		float auxx = _platformPos.x + _platformSpace.x;
		float auxy = _platformPos.y + _platformSpace.y;
		//if (min.x >= _platformPos.x-1   && min.x <= auxx)
		/*
		cout << _platformPos.y<< " <= " << min.y<<" ___ ";
		cout << _platformPos.x << " <= " << min.x << " ___ ";
			cout << auxy<< " >= "<< max.y << " ___ ";
			cout << auxx << " >= " << max.x << endl;
	*/
		//if (min.y >= _platformPos.y && min.x >=_platformPos.x && max.y <= auxy && max.x <= auxx ) {
			if (_platformPos.y >= min.y && min.x >= _platformPos.x && auxy <= max.y  && max.x <= auxx) {
			return true;
		}
		return false;
	}
}