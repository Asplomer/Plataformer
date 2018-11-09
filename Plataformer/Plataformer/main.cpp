#include <SFML\Graphics.hpp>
#include <STP\TMXLoader.hpp>
//#include <iostream>

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	tmx::TileMap map("res/Plataformer.tmx");
	map.ShowObjects(); // Display all the layer objects.

	//map.GetLayer("World").visible = false; // Hide a Layer named World


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		//window.draw(shape);
		window.draw(map);
		window.display();
	}

	return 0;
}