//Created by Noah Shannon

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;

class Player {
public:
	Player(string, string, string);
	void setStart();
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void draw(sf::RenderWindow&);
	sf::Vector2f& getPosition();
	void checkCollision(sf::Sprite);
	int getCollision();
	void setCollision(int);

private:
	sf::Texture playerFront;
	sf::Texture playerLeft;
	sf::Texture playerRight;
	sf::Sprite player;
	sf::Vector2f check;
	int collisionFlag;
};