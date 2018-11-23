#include "Manager.h"
namespace Plataformer {
	RenderWindow* window =NULL;

	int screenWidth = 0;
	int screenHeight = 0;
	int verMajor = 0;
	int verMinor = 4;
	int gameState = Play;
	float hourglass;
	float time;
//	Player* player = new Player();
//	Platform* platform = new Platform;
	void PlayTheGame(){
		InitManager();
		InitGame();
		Clock clock;
		
		tmx::TileMap map("res/Ejemtiles.tmx");

		map.ShowObjects(); // Display all the layer objects.
		while (window->isOpen())
		{
			sf::Time elapsed = clock.restart();
			Event event;
			time = elapsed.asSeconds();
			UpdateManager();
			DrawManager();
			while (window->pollEvent(event))
			{

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
		window = new RenderWindow(VideoMode(screenWidth, screenHeight), "Slimmy Adventures!");


	}
	void UpdateManager() {
		float time2=time * 100;
		hourglass += time2;
		switch (gameState) {
		case Start: {
			//UpdateStart();
		}break;
		case Play: {

			UpdateGame();

		}break;
		case GameOver: {

		}break;
		case Credit: {
			//UpdateCredit();

		}break;
		case End: {


		}break;
		}


	}
	void DrawManager() {
		window->clear();
		DrawGame();
		
		window->display();
	}
}