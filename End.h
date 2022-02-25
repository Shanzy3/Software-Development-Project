//
// Created by Mark Benhamu on 2021-11-24.
// Updated by Noah Shannon 
//
#pragma once

#ifndef QUESTIONSTATE_END_H
#define QUESTIONSTATE_END_H
using namespace std;
#include <iostream>
#include <SFML/Graphics.hpp>


class End {
public:
    End(string, string, string);
    void draw(sf::RenderWindow&);
    bool getRestartFlag();
    void setRestartFlag(bool);

private:
    sf::Texture Background;
    sf::Font font;
    sf::Text a1;
    bool RestartGame;
    sf::Sprite Eback;
    sf::RectangleShape Ebox;
    sf::Text Etext;
    sf::RectangleShape restart;
    sf::Text reStrt;
    sf::RectangleShape exit;
    sf::Text ext;

};



#endif //QUESTIONSTATE_END_H

