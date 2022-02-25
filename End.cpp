//
// Created by Mark Benhamu on 2021-11-24.
// Updated by Noah Shannon 
//
#include "end.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

End::End(string endType, string EndIMG, string Font) {
    RestartGame = false;

    Background.loadFromFile(EndIMG);
    Eback.setTexture(Background);
    Eback.setScale(416 / Eback.getLocalBounds().width, 576 / Eback.getLocalBounds().height);

    
    font.loadFromFile(Font);

    sf::Vector2f ans1Pos(155, 250);
    Ebox.setPosition(ans1Pos);
    Ebox.setSize(sf::Vector2f(125, 50));
    Ebox.setFillColor(sf::Color::Black);
    
    Etext.setFont(font);
    Etext.setCharacterSize(16);
    Etext.setString("You " + endType + "!");
    Etext.setFillColor(sf::Color::Magenta);
    Etext.setPosition(Ebox.getPosition().x + 20, Ebox.getPosition().y + 15);
    Etext.setStyle(sf::Text::Bold);

    sf::Vector2f homePos(125, 300);
    restart.setPosition(homePos);
    restart.setSize(sf::Vector2f(100, 40));
    restart.setFillColor(sf::Color::Black);
    reStrt.setFont(font);
    reStrt.setCharacterSize(15);
    reStrt.setString("Restart");
    reStrt.setFillColor(sf::Color::Cyan);
    reStrt.setPosition(restart.getPosition().x + 15, restart.getPosition().y + 10);
    reStrt.setStyle(sf::Text::Bold);

    sf::Vector2f exitPos(226, 300);
    exit.setPosition(exitPos);
    exit.setSize(sf::Vector2f(95, 40));
    exit.setFillColor(sf::Color::Black);
    ext.setFont(font);
    ext.setCharacterSize(15);
    ext.setString("Exit");
    ext.setFillColor(sf::Color::Cyan);
    ext.setPosition(exit.getPosition().x + 20, exit.getPosition().y + 10);
    ext.setStyle(sf::Text::Bold);

}

void End::draw(sf::RenderWindow& window) {
    window.draw(Eback);
    window.draw(Ebox);
    window.draw(Etext);
    window.draw(restart);
    window.draw(reStrt);
    window.draw(exit);
    window.draw(ext);
}

bool End::getRestartFlag() {
    return RestartGame;
}

void End::setRestartFlag(bool val) {
    RestartGame = val;
}