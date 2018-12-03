//#include <SFML\Graphics.hpp>
//#include <STP\TMXLoader.hpp>
//#include <iostream>
#include <ctime>
#include "Manager.h"

using namespace std;
using namespace Plataformer;

int main(){
	srand(std::time(0));
	Music music;
	if (!music.openFromFile("res/Audio/Dash Runner.wav"))
		return -1; // error
	music.play();
	PlayTheGame();
	
	//map.GetLayer("World").visible = false; // Hide a Layer named World


	

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