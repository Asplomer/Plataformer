#include "Manager.h"
namespace Plataformer {
	RenderWindow* window =NULL;

	int screenWidth = 0;
	int screenHeight = 0;
	int verMajor = 0;
	int verMinor = 25;
	Player* player = new Player();
	Platform* platform = new Platform;
	void InitManager() {
		screenWidth = 800;
		screenHeight = 400;
		window = new RenderWindow(VideoMode(screenWidth, screenHeight), "Slimmy Adventures!");
		player->InitPlayer(Vector2f( (float)50, (float)screenHeight / 5+6) );
		platform->InitPlatform(Vector2f((float)50, (float)screenHeight / 4) );
	}
	void UpdateManager(float time) {
		float time2=time * 100;
		player->UpdatePlayer(time2);
		platform->UpdatePlatform(time2);


	}
	void DrawManager() {
		window->clear();
		player->DrawPlayer();
		platform->DrawPlatform();
		window->display();
	}
	bool ColiderManager(Vector2f vec1, Vector2f vec2) {
		
		return platform->ColisionPlatform(vec1, vec2);
	}
}