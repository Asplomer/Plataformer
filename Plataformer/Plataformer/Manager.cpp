#include "Manager.h"
namespace Plataformer {
	RenderWindow* window =NULL;

	int screenWidth = 0;
	int screenHeight = 0;
	int verMajor = 0;
	int verMinor = 2;


	void InitManager() {
		screenWidth = 800;
		screenHeight = 400;
		window = new RenderWindow(VideoMode(screenWidth, screenHeight), "Slimmy Adventures!");
		
	}
}