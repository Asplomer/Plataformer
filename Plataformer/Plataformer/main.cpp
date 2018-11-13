#include <SFML\Graphics.hpp>
#include <STP\TMXLoader.hpp>
//#include <iostream>

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	tmx::TileMap map("res/Ejemtiles.tmx");
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

/*
https://www.sfml-dev.org/tutorials/2.5/graphics-transform.php

basic code for later
movement:
entity.setPosition(10.0f, 50.0f);
entity.move(5.0f, 5.0f);
sf::Vector2f position = entity.getPosition();

origin of the sprite:
entity.setOrigin(10.f, 20.f);
sf::Vector2f origin = entity.getOrigin(); // = (10, 20)

bounding box y colisiones:

// get the bounding box of the entity
sf::FloatRect boundingBox = entity.getGlobalBounds();

// check collision with a point
sf::Vector2f point = ...;
if (boundingBox.contains(point))
{
// collision!
}

// check collision with another box (like the bounding box of another entity)
sf::FloatRect otherBox = ...;
if (boundingBox.intersects(otherBox))
{
// collision!
}

textures:
https://www.sfml-dev.org/tutorials/2.5/graphics-sprite.php
*/