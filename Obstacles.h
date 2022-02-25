#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Obstacles {
public:
	Obstacles(string);
	void initializeStart(float, float);
	void moveRight(float);
	void moveLeft(float);
	void draw(sf::RenderWindow&);
	sf::Sprite getSprite();
	

private:
	sf::Texture texture;
	sf::Sprite obstacle;
	sf::Vector2f check;
	sf::FloatRect collisionBox;
};