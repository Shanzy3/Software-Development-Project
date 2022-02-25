//Created by Noah Shannon

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Background.h"

using namespace std;

ImageDoesNotExistException::ImageDoesNotExistException(const string& m) : message(m) {}
string& ImageDoesNotExistException::what() { return message; }

Background::Background(string name) {
    texture.loadFromFile(name);
    backgroundFlag = 0;
    back.setTexture(texture);
}

void Background::draw(sf::RenderWindow& window) {
    window.draw(back);
}

void Background::setFlag(int num) {
    backgroundFlag = num;
}

int Background::getFlag() {
    return backgroundFlag;
}

sf::Sprite Background::getBackground() {
    return back;
}

