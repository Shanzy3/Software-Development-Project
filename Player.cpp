//Created by Noah Shannon

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(string front, string left, string right) {
	playerFront.loadFromFile(front);
	playerLeft.loadFromFile(left);
	playerRight.loadFromFile(right);
	player.setTexture(playerFront);
	collisionFlag = 0;
}

void Player::setStart() {
	player.setPosition(192.0f, 546.0f);
}

void Player::moveUp() {
	player.setTexture(playerFront);
	player.move(0.0f, -16.0f);	
}

void Player::moveDown() {
	player.setTexture(playerFront);
	player.move(0.0f, 16.0f);
	check = player.getPosition();
	if (check.y > 546) {
		player.move(0.0f, -16.0f);
	}
}

void Player::moveLeft() {
	player.setTexture(playerLeft);
	player.move(-16.0f, 0.0f);
	check = player.getPosition();
	if (check.x < 0) {
		player.move(16.0f, 0.0f);
	}
}

void Player::moveRight() {
	player.setTexture(playerRight);
	player.move(16.0f, 0.0f);
	check = player.getPosition();
	if (check.x > 384) {
		player.move(-16.0f, 0.0f);
	}
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(player);
}

sf::Vector2f& Player::getPosition() {
	sf::Vector2f position = player.getPosition();
	return position;
}

void Player::checkCollision(sf::Sprite sprite) {
	if (player.getGlobalBounds().intersects(sprite.getGlobalBounds())) {
		collisionFlag = 1;
	}
}

int Player::getCollision() {
	return collisionFlag;
}

void Player::setCollision(int num) {
	collisionFlag = num;
}