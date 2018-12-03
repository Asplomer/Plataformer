#include "Manager.h"
namespace Plataformer {
	RenderWindow* window =NULL;

	int screenWidth = 0;
	int screenHeight = 0;
	String verMajor = '0';
	String verMinor = '9';
	int gameState = Start;
	float hourglass;
	float time;
	Font font;
	Text text;
//	Player* player = new Player();
//	Platform* platform = new Platform;
	void PlayTheGame(){

		text.setFont(font);
		text.setFillColor(Color::White);
		
		InitManager();
		InitCredits();
		InitStart();
		InitGame();
		Clock clock;
		
		tmx::TileMap map("res/Ejemtiles.tmx");

		map.ShowObjects(); // Display all the layer objects.
		while (window->isOpen()){
			sf::Time elapsed = clock.restart();
			Event event;
			time = elapsed.asSeconds();
			UpdateManager();
			DrawManager();
			while (window->pollEvent(event)){

				if (event.type == Event::Closed)
					window->close();
			}

			window->clear();

			//window.draw(shape);
			window->draw(map);

			//player->DrawPlayer();


		}
	}
	void InitManager() {
		screenWidth = 800;
		screenHeight = 400;
		window = new RenderWindow(VideoMode(screenWidth, screenHeight), "Slimy Adventures!");
		if (!font.loadFromFile("res/Imagenes/arial.ttf")){
			// error...
		}

	}
	void UpdateManager() {
		float time2=time * 100;
		hourglass += time2;
		switch (gameState) {
		case Start: {
			UpdateStart();
			
		}break;
		case Play: {

			UpdateGame();

		}break;
		case GameOver: {

		}break;
		case Credit: {
			//cout << "creditos aca"<<endl;
			UpdateCredits();

		}break;
		case End: {
			window->close();

		}break;
		}


	}
	void DrawManager() {
		window->clear();
		switch (gameState) {
		case Start: {
			DrawStart();
		}break;
		case Play: {

			DrawGame();

		}break;
		case GameOver: {

		}break;
		case Credit: {
			DrawCredits();

		}break;
		case End: {


		}break;
		}
		//DrawGame();
		
		window->display();
	}
}