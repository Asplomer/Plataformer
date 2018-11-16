#include "Player.h"
namespace Plataformer {
	static Texture _playerTextures[1];
	void Player::InitPlayer(Vector2f vec) {
		_playerPos = vec;
		_playerSpace = { 32.0f,32.0f };
		_momentum = 0.0f;
		_jump = false;
		
			if (!_playerTextures[0].loadFromFile("res/Slime.png"))
			{
				// error...
			}
			_playerSprite.setPosition(_playerPos);
	}
	void Player::UpdatePlayer() {
		InputPlayer();
		_playerSprite.setPosition(_playerPos);
		DrawPlayer();
	}
	void Player::DrawPlayer() {
		_playerSprite.setTexture(_playerTextures[0]);
		
		window->draw(_playerSprite);
	}
	void Player::InputPlayer() {
		if (Keyboard::isKeyPressed(Keyboard::Right))
			_playerPos.x += 0.5f;
		if (Keyboard::isKeyPressed(Keyboard::Left))
			_playerPos.x -= 0.5f;
		if (_jump == false) {
			if (Keyboard::isKeyPressed(Keyboard::Space) && _jump == false) {
				_jump = true;
				_momentum = 2.0f;
			}
		}
		else {
			
			_playerPos.y -= _momentum / 4;
			_momentum -=0.01f;
			//COLISIONES
			if (_momentum <= -2.0f)
				_jump = false;
		}

	}
	void Player::UnloadPlayer() {

	}
	bool Player::OnGroundPlayer() {
		return false;
	}

}