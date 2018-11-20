#include "Player.h"
namespace Plataformer {
	static Texture _playerTextures[1];
	void Player::InitPlayer(Vector2f vec) {
		_playerPos = vec;
		_playerSpace = { 32.0f,32.0f };
		_momentum = 0.0f;
		_jump = true;
		
			if (!_playerTextures[0].loadFromFile("res/Slime.png"))
			{
				// error...
			}
			_playerSprite.setPosition(_playerPos);
	}
	void Player::UpdatePlayer(float time) {
		InputPlayer(time);
		_playerSprite.setPosition(_playerPos);
		DrawPlayer();
	}
	void Player::DrawPlayer() {
		_playerSprite.setTexture(_playerTextures[0]);
		
		window->draw(_playerSprite);
	}
	void Player::InputPlayer(float time) {
		if (Keyboard::isKeyPressed(Keyboard::Right))
			_playerPos.x += 0.50f*time;
		if (Keyboard::isKeyPressed(Keyboard::Left))
			_playerPos.x -= 0.50f*time;
		_playerPos.y -= _momentum /2 * time;
		if (_jump == false) {
			if (Keyboard::isKeyPressed(Keyboard::Space) ) {
				_jump = true;
				_momentum = 2.0f;
			}
		}
		else {
			//COLISIONES
			
			Vector2f aux = { _playerPos.x + _playerSpace.x / 2, _playerPos.y + _playerSpace.y / 2 };
			Vector2f aux2 = { _playerPos.x + _playerSpace.x * 2, _playerPos.y + _playerSpace.y * 2 };
			

			//if (/*_momentum <= -2.0f*/ColiderManager(_playerPos, aux)) {

			//if (/*_momentum <= -2.0f*/ColiderManager(aux, _playerPos)) {
			if (/*_momentum <= -2.0f*/ColiderManager(aux, aux2)) {
				_jump = false;
				_momentum = 0.0f;
			}
			else {
				_jump = true;
				
				_momentum -= 0.05f*time;

			}

		}
		

	}
	void Player::UnloadPlayer() {

	}
	bool Player::OnGroundPlayer() {
		return false;
	}

}