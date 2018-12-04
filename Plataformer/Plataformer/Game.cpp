#include "Game.h"
namespace Plataformer {
	Player* player = new Player();
	//Platform* platform = new Platform;
	Platform* platformArray[PLATFORMARRAYSIZE];
	Enemy* eye = new Enemy();
	void InitGame() {
		BoundingBox ch = { (float)70, (float)screenHeight / 6 - 16 , 22.0f, 16.0f };
		BoundingBox p1 = { (float)50, (float)screenHeight / 3 + 20,  128.0f, 32.0f };
		BoundingBox p2 = { (float)screenWidth / 2 + 10, (float)screenHeight / 2 - 100,  128.0f, 32.0f };
		BoundingBox p3 = { (float)screenWidth / 2 - 150, (float)screenHeight / 2  ,  128.0f, 32.0f };
		BoundingBox p4 = { (float)screenWidth - 200, (float)screenHeight / 3 + 20,  128.0f, 32.0f };
		player->InitPlayer(ch);
		for (int i = 0; i < PLATFORMARRAYSIZE; i++) {
			platformArray[i] = new Platform;

		}

		platformArray[0]->InitPlatform(p1, 2, 1);
		platformArray[1]->InitPlatform(p2, 0, 1);
		platformArray[2]->InitPlatform(p3, 0, 2);
		platformArray[3]->InitPlatform(p4, 1, 1);
		Vector2f measuresEye = { 48.0f, 48.0f };
		eye->InitEnemy(ch, measuresEye);
	}
	bool DetectCol(BoundingBox rect1, BoundingBox rect2) {
		if (rect1.x < rect2.x + rect2.w &&
			rect1.x + rect1.w > rect2.x &&
			rect1.y < rect2.y + rect2.h &&
			rect1.h + rect1.y >rect2.y)
			return true;
		return false;
	}
	void UpdateGame() {
		float aux1 = 0.0f;
		float aux2 = 0.0f;
		bool aux3 = false;		//si el jugador esta atacando
		bool colides = false;
		if (DetectCol(player->BoundingPlayer(), eye->BoundingEnemy()) || player->BoundingPlayer().y> screenHeight) {
			gameState = Start;
			InitGame();
		}
		for (int i = 0; i < PLATFORMARRAYSIZE; i++){
			platformArray[i]->UpdatePlatform();
			if (DetectCol(player->BoundingPlayer(), platformArray[i]->BoundingPlatform())) {
				colides = true;
				aux1 = platformArray[i]->ReturnMovementPlatformx();
				aux2 = platformArray[i]->ReturnMovementPlatformy();
			}
		}


		aux3 = player->UpdatePlayer(aux1, aux2);
		eye->UpdateEnemy(player->BoundingPlayer());
		if (aux3 && DetectCol(eye->BoundingEnemy(), player->BoundingAtack())) {

			eye->RespawnEnemy(player->BoundingPlayer());
		}
		else {
			BoundingBox bE = eye->BoundingEnemy();
			BoundingBox bA = player->BoundingAtack();
			//cout << bE.y<<  " vs "<< bA.y  << endl;
		}

		player->PlayerJump(colides);


	}
	void DrawGame() {
		tmx::TileMap map("res/Imagenes/Background.tmx");
		map.ShowObjects();
		window->draw(map);

		player->DrawPlayer();
		eye->DrawEnemy();

		for (int i = 0; i < PLATFORMARRAYSIZE; i++){
			platformArray[i]->DrawPlatform();
		}

	}
}