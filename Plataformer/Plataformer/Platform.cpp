#include "Platform.h"

namespace Plataformer {
	static Texture _platf;
	void Platform::InitPlatform(BoundingBox box, int t1, int t2) {
		_speedx = 0.0f;
		_speedy = 0.0f;
		//_platformPos = vec;
		_boxPlatform = box;
		_type1 = t1;
		_type2 = t2;
		_mult = 200.0f;
		if ((_type1 == 1 || _type1 == 2) && (_type2 == 1 || _type2 == 2))
			_mult = 100.0f;
		if (!_platf.loadFromFile("res/Imagenes/Plataforma/PlatformSimple.png")){
			// error...
		}
		
	}
	void Platform::UpdatePlatform() {
		//8 de ancho* alto

		if (_type1 == 0) {
			_speedx = 0.0f;
		}
		if (_type1 == 1) {
			_speedx = sin((float)hourglass / 50)* PLATFORMSPEED;
		}
		if (_type1 == 2) {
			_speedx = sin(-1 * (float)hourglass / 50)* PLATFORMSPEED;
		}
		if (_type2 == 0) {
			_speedy = 0.0f;
		}
		if (_type2 == 1) {
			_speedy = sin((float)hourglass / 50)* PLATFORMSPEED;
		}
		if (_type2 == 2) {
			_speedy =  sin(-1 * (float)hourglass / 50)* PLATFORMSPEED;
		}

		_boxPlatform.x += _speedx * _mult * time;
		//cout << _boxPlatform.x<<endl;
		_boxPlatform.y += _speedy * _mult * time;
		_platfSprite.setPosition(Vector2f{ _boxPlatform.x, _boxPlatform.y });
	}
	void Platform::DrawPlatform() {

		_platfSprite.setTexture(_platf);

		window->draw(_platfSprite);
	}
	float Platform::ReturnMovementPlatformx() {
		return _speedx * _mult * time;
	}
	float Platform::ReturnMovementPlatformy() {
		return _speedy * _mult * time;
	}
	BoundingBox Platform::BoundingPlatform() {
		//BoundingBox aux = { _boxPlatform.x, _boxPlatform.y, _boxPlatform.x, _boxPlatform.y};
		return _boxPlatform;
	}

}