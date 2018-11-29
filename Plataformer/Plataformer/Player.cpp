#include "Player.h"
namespace Plataformer {
	static Texture _playerTextures[2];
	void Player::InitPlayer(BoundingBox box) {
		_boxPlayer = box;
		
		
		_momentum = 0.0f;
		_jump = true;
		_atacking = false;
		_atackCD = false;
			if (!_playerTextures[0].loadFromFile("res/Slime/Slime.png"))
			{
				// error...
			}
			if (!_playerTextures[1].loadFromFile("res/Slime/Atack.png"))
			{
				// error...
			}
			_playerSprite.setPosition(_boxPlayer.x, _boxPlayer.y);
			_atackSprite.setPosition(_boxPlayer.x + 32.0f, _boxPlayer.y + 16.0f);
	}

	void Player::UpdatePlayer(float aux1, float aux2) {
		
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
			cout << "esta atacando: "<< _atackStart << endl;
		}
		else cout << "no lo esta " <<_atackStart<< endl;
		DrawPlayer();
	}
	void Player::DrawPlayer() {
		
		_playerSprite.setPosition(Vector2f{ _boxPlayer.x, _boxPlayer.y });
				_playerSprite.setTexture(_playerTextures[0]);
		
		window->draw(_playerSprite);
		if (_atacking) {
			
			
			_atackSprite.setPosition(_boxPlayer.x + 16.0f, _boxPlayer.y);
			_atackSprite.setTexture(_playerTextures[1]);
			window->draw(_atackSprite);


		}
	}
	void Player::InputPlayer() {
		if (Keyboard::isKeyPressed(Keyboard::Right))
			_boxPlayer.x += PLAYERSPEED * time*100;
		if (Keyboard::isKeyPressed(Keyboard::Left))
			_boxPlayer.x -= PLAYERSPEED * time*100;
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
			cout << "ataca!" << endl;
			_atackStart = 10.0f;
			_atackCD = true;
			_atackCooldown = 40.0f;
		}
		if (Keyboard::isKeyPressed(Keyboard::C))
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
	float Player::AngleToPlayer(BoundingBox from) {
		double tgX = from.x - _boxPlayer.x;
		double tgy = from.y - _boxPlayer.y;
		return atan2(tgX, tgy);
	}
	BoundingBox Player::BoundingPlayer(){
		return _boxPlayer;
	}
}