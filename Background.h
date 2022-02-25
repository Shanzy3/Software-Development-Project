//Created by Noah Shannon

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;

class ImageDoesNotExistException {
public:
	ImageDoesNotExistException(const string&);
	string& what();
private:
	string message;
};

class Background {
public:
	Background (string);
	void setFlag(int);
	int getFlag();
	sf::Sprite getBackground();
	void draw(sf::RenderWindow&);

private:
	sf::Texture texture;
	int backgroundFlag;
	sf::Sprite back;
};