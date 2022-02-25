//
// Created by Mark Benhamu on 2021-11-24.
// Updated by Noah Shannon 
//

#pragma once

#ifndef QUESTIONSTATE_QUESTION_H
#define QUESTIONSTATE_QUESTION_H
#include <SFML/Graphics.hpp>
using namespace std;


class Question {
public:
    Question(int, string, string);
    void setCorrect(bool);
    void setIncorrect(bool);
    bool getCorrect();
    bool getIncorrect();
    void draw(sf::RenderWindow&);

private:
    sf::Texture background;
    sf::Font font;
    sf::Sprite backQ;
    sf::Text question;
    sf::RectangleShape ans1;
    sf::Text a1;
    sf::RectangleShape ans2;
    sf::Text a2;
    sf::RectangleShape ans3;
    sf::Text a3;
    bool correct;
    bool incorrect;
}; 
#endif

