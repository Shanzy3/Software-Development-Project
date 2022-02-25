//
// Created by Mark Benhamu on 2021-11-24.
// Updated by Noah Shannon 
//

#include "StartS.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

startS::startS(string backIMG, string fontFILE) {
    start = false;
    
    brIMG.loadFromFile(backIMG);
    back.setTexture(brIMG);
    back.setScale(416 / back.getLocalBounds().width, 576 / back.getLocalBounds().height);

    
    font.loadFromFile(fontFILE);


    sf::Vector2f ans1Pos(150, 400);
    result.setPosition(ans1Pos);
    result.setSize(sf::Vector2f(125, 40));
    result.setFillColor(sf::Color::Black);

    a1.setFont(font);
    a1.setCharacterSize(16);
    a1.setString("Start Game!");
    a1.setFillColor(sf::Color::Magenta);
    check = result.getPosition();
    a1.setPosition(check.x + 10, check.y + 5);
    a1.setStyle(sf::Text::Bold);


}

bool startS::getStart() {
    return start;
}

void startS::setStart(bool var) {
    start = var;
}

void startS::draw(sf::RenderWindow& window) {
    window.draw(back);
    window.draw(result);
    window.draw(a1);
}