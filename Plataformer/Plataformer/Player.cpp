#include "Player.h"
namespace Plataformer {
	static Texture _playerTextures[3];
	void Player::InitPlayer(BoundingBox box) {
		_boxPlayer = box;		//la posicion del jugador en la pantalla y sus dimensiones
		
		
		_momentum = 0.0f;		// el momentum que se genera cuando se mueve en el aire, para calcular el salto
		_jump = true;			// si esta saltando/ en el aire
		_atacking = false;		// si esta atacando el jugador
		_atackCD = false;		// si esta en cd el ataque del jugador
		_direction = false;		//si es false, mira para la derecha
		
			if (!_playerTextures[0].loadFromFile("res/Imagenes/Slime/Slime.png")){
				// error...
			}
			if (!_playerTextures[1].loadFromFile("res/Imagenes/Slime/Atack.png")){
				// error...
			}
			if (!_playerTextures[2].loadFromFile("res/Imagenes/Slime/Atack2.png")){
				// error...
			}
			_playerSprite.setPosition(_boxPlayer.x, _boxPlayer.y);
			//_boxAtack = BoundingBox{ (float)_boxPlayer.x, (float)_boxPlayer.y, (float)_boxPlayer.w, (float)_boxPlayer.h };
			_atackSprite.setPosition(_boxPlayer.x + 32.0f, _boxPlayer.y + 16.0f);
	}
	bool Player::UpdatePlayer(float aux1, float aux2) {
		bool ret = false;
		_boxPlayer.x += aux1;
		_boxPlayer.y += aux2;
		InputPlayer();
		if (_atacking) {
			_atackStart -= time * 100;
			
		}if (_atackStart < 0.0f) {
			//_atackDuration += time * 100;
			_atacking = false;
			_atackStart = 5.0f;
			
		}
		if(_atackCD){
		_atackCooldown -= time*100;
		if (_atackCooldown <= 0.0f)
			_atackCD = false;
		}
		//cout << _atackDuration << " vs " << _atackStart << " = " << _atackStart - _atackDuration <<endl;
		if (_atacking) {
			ret = true;
		}
		else ret = false;
		DrawPlayer();
		return ret;
	}
	void Player::DrawPlayer() {
		
		_playerSprite.setPosition(Vector2f{ _boxPlayer.x, _boxPlayer.y });
		_playerSprite.setTexture(_playerTextures[0]);
		

		if (_atacking) {
			
			if (!_direction) {
				_atackSprite.setPosition(_boxPlayer.x + _boxPlayer.w/2, _boxPlayer.y);
				_atackSprite.setTexture(_playerTextures[1]);
			}
			else {
				_atackSprite.setPosition(_boxPlayer.x - _boxPlayer.w, _boxPlayer.y);
				_atackSprite.setTexture(_playerTextures[2]);
			}
			
			window->draw(_atackSprite);
			

		}
		window->draw(_playerSprite);
	}
	void Player::InputPlayer() {
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			_boxPlayer.x += PLAYERSPEED * time * 100;
			if (!_atacking)
			_direction = false;
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			_boxPlayer.x -= PLAYERSPEED * time * 100;
			if(!_atacking)
			_direction = true;
		}
		_boxPlayer.y -= _momentum /2 * time*100;
		if (_jump == false) {
			if (Keyboard::isKeyPressed(Keyboard::X) ) {
				_jump = true;
				_momentum = 3.6f;
				_boxPlayer.x--;
				_boxPlayer.y--;
			}
		}
		if (!_atacking && Keyboard::isKeyPressed(Keyboard::Z) && !_atackCD ){
			_atacking = true;
			//cout << "ataca!" << endl;
			_atackStart = 10.0f;
			_atackCD = true;
			_atackCooldown = 40.0f;
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			window->close();
	}
	void Player::UnloadPlayer() {

	}
	bool Player::OnGroundPlayer() {
		if(_jump = false)
		return false;

		return true;
	}
	bool Player::PlayerJump(bool colision){
		if (colision) {
			_jump = false;
			_momentum = 0.0f;
			return false;
		}
		
		else {
			_momentum -= 0.08f * time*100;
			return true;
		}
	}
	BoundingBox Player::BoundingAtack() {
		BoundingBox b = { (float)_boxPlayer.x, (float)_boxPlayer.y, (float)_boxPlayer.w, (float)_boxPlayer.h };
		if (_direction) {
			b.x -= _boxPlayer.w/2;
		}
		else {
			b.x += _boxPlayer.w;
		}
		return b;
	}
	float Player::AngleToPlayer(BoundingBox from) {
		double tgX = from.x - _boxPlayer.x;
		double tgy = from.y - _boxPlayer.y;
		return (float)atan2(tgX, tgy);
	}
	BoundingBox Player::BoundingPlayer(){
		return _boxPlayer;
	}
	
}