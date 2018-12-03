#include "Credits.h"
namespace Plataformer {
	String _ctextStr[TEXTNUMBERCREDITS];
	int _ctextSiz[TEXTNUMBERCREDITS];
	int _ctextPosX[TEXTNUMBERCREDITS];
	int _ctextPosY[TEXTNUMBERCREDITS];
	void InitCredits() {
		_ctextStr[0] = ("SlimePanic");
		String aux = "Version V";

		aux.insert(aux.getSize(), verMajor);
		aux.insert(aux.getSize(), '.');
		aux.insert(aux.getSize(), verMinor);
		_ctextStr[1] = (aux);
		_ctextStr[2] = "";
		_ctextStr[3] = "Start";

		_ctextSiz[0] = 40;
		_ctextSiz[1] = 28;
		_ctextSiz[2] = 28;
		_ctextSiz[3] = 28;

		_ctextPosX[0] = 75.0f;
		_ctextPosY[0] = 10.0f;

		_ctextPosX[1] = 75.0f;
		_ctextPosY[1] = 120.0f;

		_ctextPosX[2] = 75.0f;
		_ctextPosY[2] = 200.0f;

		_ctextPosX[3] = 325.0f;
		_ctextPosY[3] = 280.0f;
	}
	void UpdateCredits() {
		Vector2i aux = Mouse::getPosition();
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (aux.x - 400 > 350 && aux.x - 400 < 555 && aux.y - 250 >280 && aux.y - 250 < 350) {
				gameState = Start;
			}
			
		}
	}
	void DrawCredits(){
		

		for (int i = 0; i < TEXTNUMBERCREDITS; i++)
		{
			//aca esta el error!
			String aux = _ctextStr[i];
			//cout << aux << endl;

			text.setString(aux);
			text.setPosition(Vector2f(_ctextPosX[i], _ctextPosY[i]));
			text.setCharacterSize(_ctextSiz[i]);
			text.setStyle(sf::Text::Bold);
			window->draw(text);
		}
	}

}