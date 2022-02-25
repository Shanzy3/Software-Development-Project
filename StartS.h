//
// Created by Mark Benhamu on 2021-11-24.
// Updated by Noah Shannon 
//
#pragma once

#ifndef QUESTIONSTATE_STARTS_H
#define QUESTIONSTATE_STARTS_H
#include <SFML/Graphics.hpp>
using namespace std;

class startS {
public:
    startS(string, string);
    bool getStart();
    void setStart(bool);
    void draw(sf::RenderWindow&);
private:
    sf::Sprite back;
    bool start;
    sf::RectangleShape result;
    sf::Text a1;
    sf::Texture brIMG;
    sf::Vector2f check;
    sf::Font font;
};


#endif //QUESTIONSTATE_STARTS_H
