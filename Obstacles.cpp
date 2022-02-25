#include <iostream>
#include <SFML/Graphics.hpp>
#include "Obstacles.h"

using namespace std;

Obstacles::Obstacles(string file) {
	texture.loadFromFile(file);
	obstacle.setTexture(texture);
	obstacle.scale(1.15f, 1.15f);
}

void Obstacles::initializeStart(float x, float y) {
	obstacle.setPosition(x, y);
}

void Obstacles::moveLeft(float speed) {
	obstacle.move(-speed, 0.0f);
	check = obstacle.getPosition();
	if (check.x <= -32) {
		obstacle.setPosition(576.0f, check.y);
	}
}

void Obstacles::moveRight(float speed) {
	obstacle.move(speed, 0.0f);
	check = obstacle.getPosition();
	if (check.x >= 416) {
		obstacle.setPosition(-32.0f, check.y);
	}
}

void Obstacles::draw(sf::RenderWindow& window) {
	window.draw(obstacle);
}

sf::Sprite Obstacles::getSprite() {
	return obstacle;
}

