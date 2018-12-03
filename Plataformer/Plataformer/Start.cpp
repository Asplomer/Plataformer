#include "Start.h"

namespace Plataformer {


	String _stextStr[TEXTNUMBERSTART];
	int _stextSiz[TEXTNUMBERSTART];
	int _stextPosX[TEXTNUMBERSTART];
	int _stextPosY[TEXTNUMBERSTART];
	void InitStart() {
		_stextStr[0] = ("Slimy adventures");
		String aux = "Version V";

		aux.insert(aux.getSize(), verMajor);
		aux.insert(aux.getSize(), '.');
		aux.insert(aux.getSize(), verMinor);

		_stextStr[1] = (aux);
		_stextStr[2] = ("Play");
		_stextStr[3] = ("Exit");
		_stextStr[4] = ("Credits");

		_stextSiz[0] = 40;
		_stextSiz[1] = 28;
		_stextSiz[2] = 28;
		_stextSiz[3] = 28;
		_stextSiz[4] = 28;

		_stextPosX[0] = 75.0f;
		_stextPosY[0] = 10.0f;

		_stextPosX[1] = 75.0f;
		_stextPosY[1] = 120.0f;

		_stextPosX[2] = 75.0f;
		_stextPosY[2] = 200.0f;

		_stextPosX[3] = 75.0f;
		_stextPosY[3] = 280.0f;

		_stextPosX[4] = 75.0f;
		_stextPosY[4] = 340.0f;

	}
	void UpdateStart() {
		Vector2i aux = Mouse::getPosition(*window);
		//el 400 tiene desde el borde derecho hacia el inicio de la pantalla, que es medio raro
		cout << aux.x  << " de x y " << aux.y<< " de y" << endl;

		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (aux.x >  65 && aux.x  <  285 && aux.y>200  && aux.y < 230 ) {
				
				gameState = Play;
				
			}
			if (aux.x > 65 && aux.x < 255 && aux.y >280 && aux.y < 315) {
				gameState = End;
			}
			
			if (aux.x > 65 && aux.x < 255 && aux.y >340 && aux.y < 375) {
				gameState = Credit;
			}
		}
	}
	void DrawStart() {

		for (int i = 0; i < TEXTNUMBERSTART; i++){
			text.setString(_stextStr[i]);
			text.setPosition(Vector2f( _stextPosX[i], _stextPosY[i]));
			text.setCharacterSize(_stextSiz[i]);
			text.setStyle(sf::Text::Bold );
			window->draw(text);
		}
	}
}