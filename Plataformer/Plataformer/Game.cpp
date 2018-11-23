#include "Game.h"
namespace Plataformer {
	Player* player = new Player();
	//Platform* platform = new Platform;
	Platform* platformArray[PLATFORMARRAYSIZE];
	void InitGame() {
		BoundingBox ch = { (float)50, (float)screenHeight / 6 - 16 , 32.0f, 32.0f };	
		BoundingBox p1 = { (float)50, (float)screenHeight / 3 +20,  128.0f, 32.0f };
		BoundingBox p2 = { (float)screenWidth / 2 +10, (float)screenHeight / 2 -100,  128.0f, 32.0f };
		BoundingBox p3 = { (float)screenWidth / 2 -150, (float)screenHeight /2  ,  128.0f, 32.0f };
		BoundingBox p4 = { (float)screenWidth - 200, (float)screenHeight / 3 +20,  128.0f, 32.0f };
		player->InitPlayer(ch);
		for (int i = 0; i < PLATFORMARRAYSIZE; i++){
			platformArray[i] = new Platform;

		}
		
		platformArray[0]->InitPlatform(p1, 2, 1);
		platformArray[1]->InitPlatform(p2, 0, 1);
		platformArray[2]->InitPlatform(p3, 0, 2);
		platformArray[3]->InitPlatform(p4, 1, 1);
	}


bool DetectCol(BoundingBox rect1, BoundingBox rect2){
	if (rect1.x < rect2.x + rect2.w &&
		rect1.x + rect1.w > rect2.x &&
		rect1.y < rect2.y + rect2.h &&
		rect1.h + rect1.y >rect2.y)
		return true;
	return false;
}
void MovingPlatforms() {

}

void UpdateGame() {
	float aux1 = 0.0f;
	float aux2 = 0.0f;
	bool colides = false;
	for (int i = 0; i < PLATFORMARRAYSIZE; i++)
	{
		platformArray[i]->UpdatePlatform();
		if (DetectCol(player->BoundingPlayer(), platformArray[i]->BoundingPlatform())) {
			colides = true;
			aux1 = platformArray[i]->ReturnMovementPlatformx();
			aux2 = platformArray[i]->ReturnMovementPlatformy();
		}
	}
	

	
	

	player->UpdatePlayer(aux1, aux2);
	player->PlayerJump(colides);
	

	}
void DrawGame() {
	player->DrawPlayer();
	for (int i = 0; i < PLATFORMARRAYSIZE; i++)
	{
		platformArray[i]->DrawPlatform();
	}
	
	}
}