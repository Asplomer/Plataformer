#include "Player.h"
namespace Plataformer {
	static Texture _playerTextures[1];
	void Player::InitPlayer(BoundingBox box) {
		_boxPlayer = box;
		_momentum = 0.0f;
		_jump = true;	
			if (!_playerTextures[0].loadFromFile("res/Slime.png"))
			{
				// error...
			}

			_playerSprite.setPosition(_boxPlayer.x, _boxPlayer.y);
	}

	void Player::UpdatePlayer(float aux1, float aux2) {
		
		_boxPlayer.x += aux1;
		_boxPlayer.y += aux2;
		InputPlayer();
		DrawPlayer();
	}
	void Player::DrawPlayer() {
		_playerSprite.setPosition(Vector2f{ _boxPlayer.x, _boxPlayer.y });

		_playerSprite.setTexture(_playerTextures[0]);
		
		window->draw(_playerSprite);
	}
	void Player::InputPlayer() {
		if (Keyboard::isKeyPressed(Keyboard::Right))
			_boxPlayer.x += PLAYERSPEED * time*100;
		if (Keyboard::isKeyPressed(Keyboard::Left))
			_boxPlayer.x -= PLAYERSPEED * time*100;
		_boxPlayer.y -= _momentum /2 * time*100;
		if (_jump == false) {
			if (Keyboard::isKeyPressed(Keyboard::Space) ) {
				_jump = true;
				_momentum = 3.6f;
				_boxPlayer.x--;
				_boxPlayer.y--;
			}
		}
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
	BoundingBox Player::BoundingPlayer(){
		return _boxPlayer;
	}
}