//
// Created by Mark Benhamu on 2021-11-24.
// Updated by Noah Shannon 
//
#include <iostream>
#include "Question.h"
#include <SFML/Graphics.hpp>
using namespace std;

Question::Question(int num, string backgroundIM, string fnt) {
    correct = false;
    incorrect = false;
    
    background.loadFromFile(backgroundIM);
    backQ.setTexture(background);
    backQ.setScale(416 / backQ.getLocalBounds().width, 576 / backQ.getLocalBounds().height);

    font.loadFromFile(fnt);

    //sf::Text question;
    question.setFont(font);
    question.setCharacterSize(12);
    question.setFillColor(sf::Color::Black);
    question.setPosition(100, 100);
    question.setStyle(sf::Text::Bold);

    //sf::RectangleShape ans1;
    sf::Vector2f ans1Pos(100, 400);
    ans1.setPosition(ans1Pos);
    ans1.setSize(sf::Vector2f(75, 50));
    ans1.setFillColor(sf::Color::Red);

    //sf::Text a1;
    a1.setFont(font);
    a1.setCharacterSize(12);
    a1.setFillColor(sf::Color::Black);
    a1.setPosition(ans1.getPosition().x + 5, ans1.getPosition().y + 5);
    a1.setStyle(sf::Text::Bold);

    //sf::RectangleShape ans2;
    sf::Vector2f ans2Pos(175, 400);
    ans2.setPosition(ans2Pos);
    ans2.setSize(sf::Vector2f(75, 50));
    ans2.setFillColor(sf::Color::Yellow);

    //sf::Text a2;
    a2.setFont(font);
    a2.setCharacterSize(12);
    a2.setFillColor(sf::Color::Black);
    a2.setPosition(ans2.getPosition().x + 5, ans2.getPosition().y + 5);
    a2.setStyle(sf::Text::Bold);

    //sf::RectangleShape ans3;
    sf::Vector2f ans3Pos(250, 400);
    ans3.setPosition(ans3Pos);
    ans3.setSize(sf::Vector2f(75, 50));
    ans3.setFillColor(sf::Color::Blue);

    //sf::Text a3;
    a3.setFont(font);
    a3.setCharacterSize(12);
    a3.setFillColor(sf::Color::Black);
    a3.setPosition(ans3.getPosition().x + 5, ans3.getPosition().y + 5);
    a3.setStyle(sf::Text::Bold);

    switch (num) {
    case 1:
        question.setString("When was Queen's Founded?");
        a1.setString("1841");
        a2.setString("1869");
        a3.setString("1856");
        break;
    case 2:
        question.setString("Best course offered @ Queen's?");
        a1.setString("CMPE 320");
        a2.setString("ELEC 371");
        a3.setString("APSC 151");
        break;
    case 3:
        question.setString("Best Ice cream in Ktown?");
        a1.setString("Mio Gelato");
        a2.setString("DQ");
        a3.setString("McDonald's");
        break;
    }

}

void Question::setCorrect(bool val) {
    correct = val;
}

void Question::setIncorrect(bool val) {
    incorrect = val;
}

bool Question::getCorrect() {
    return correct;
}

bool Question::getIncorrect() {
    return incorrect;
}

void Question::draw(sf::RenderWindow& window) {
    window.draw(backQ);
    window.draw(question);
    window.draw(ans1);
    window.draw(a1);
    window.draw(ans2);
    window.draw(a2);
    window.draw(ans3);
    window.draw(a3);
}
