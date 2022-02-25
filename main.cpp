//Created by Noah Shannon using similar code to Mark Benhamu


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Background.h"
#include "Player.h"
#include "Question.h"
#include "StartS.h"
#include "End.h"
#include "Obstacles.h"
#include <iostream>

using namespace std;

int main()
{   
    //Flags used thoughout main to tell the game when to run certain parts of code
    int gameOver = 0;
    int loss = 0;
    int initFlag = 0;
    int questionFlag = 0;

    //window the game is played in 
    sf::RenderWindow window(sf::VideoMode(416, 576), "Game");
    sf::Event event;

    window.setFramerateLimit(60);

    //all the backgounds used for the game
    Background back1("GameBackground1.png");
    Background back2("GameBackground2.png");
    Background back3("GameBackground3.png");

    //Initializing all the cars and bikes for the game
    Obstacles r1Car1("CarRight.png");
    Obstacles r1Car2("CarRight.png");
    Obstacles r1Car3("CarRight.png");

    Obstacles r2Car1("CarLeft.png");
    Obstacles r2Car2("CarLeft.png");
    Obstacles r2Car3("CarLeft.png");
    Obstacles r2Car4("CarLeft.png");

    Obstacles r3Car1("CarLeft.png");
    Obstacles r3Car2("CarLeft.png");

    Obstacles r4Car1("CarLeft.png");
    Obstacles r4Car2("CarLeft.png");
    Obstacles r4Car3("CarLeft.png");
    Obstacles r4Car4("CarLeft.png");

    Obstacles b1Bike1("BikeRight.png");
    Obstacles b1Bike2("BikeRight.png");

    Obstacles b2Bike1("BikeLeft.png");
    Obstacles b2Bike2("BikeLeft.png");

    Obstacles r5Car1("CarRight.png");
    Obstacles r5Car2("CarRight.png");

    Obstacles r6Car1a("CarRight.png");
    Obstacles r6Car2a("CarRight.png");
    Obstacles r6Car3a("CarRight.png");

    Obstacles r6Car1b("CarLeft.png");
    Obstacles r6Car2b("CarLeft.png");
    Obstacles r6Car3b("CarLeft.png");

    Obstacles r7Car1("CarRight.png");

    //Initializing all car's start position in game
    r1Car1.initializeStart(0.0f, 15.0f);
    r1Car2.initializeStart(75.0f, 15.0f);
    r1Car3.initializeStart(375.0f, 15.0f);

    r2Car1.initializeStart(0.0f, 48.0f);
    r2Car2.initializeStart(50.0f, 48.0f);
    r2Car3.initializeStart(100.0f, 48.0f);
    r2Car4.initializeStart(150.0f, 48.0f);

    r3Car1.initializeStart(200.0f, 100.0f);
    r3Car2.initializeStart(400.0f, 100.0f);

    r4Car1.initializeStart(300.0f, 165.0f);
    r4Car2.initializeStart(350.0f, 165.0f);
    r4Car3.initializeStart(400.0f, 165.0f);

    b1Bike1.initializeStart(0.0f, 287.0f);
    b1Bike2.initializeStart(125.0f, 287.0f);

    b2Bike1.initializeStart(175.0f, 327.0f);
    b2Bike2.initializeStart(300.0f, 327.0f);

    r5Car1.initializeStart(100.0f, 370.0f);
    r5Car2.initializeStart(400.0f, 370.0f);

    r6Car1a.initializeStart(0.0f, 415.0f);
    r6Car2a.initializeStart(50.0f, 415.0f);
    r6Car3a.initializeStart(200.0f, 415.0f);

    r6Car1b.initializeStart(100.0f, 440.0f);
    r6Car2b.initializeStart(150.0f, 440.0f);
    r6Car3b.initializeStart(200.0f, 440.0f);

    r7Car1.initializeStart(250.0f, 530.0f);
    //Player creation
    Player player("Player.png", "PlayerLeft.png", "PlayerRight.png");
    player.setStart();

    //start screen initialization
    startS start("froshy_road.png", "arial.ttf");
    
    //A1 used for start screen, A2 and A3 used for end screen
    //A4,5 and 6 used for question prompts
    const sf::Rect<int> &A1 = sf::IntRect(150, 400, 125, 40);
    const sf::Rect<int> &A2 = sf::IntRect(125, 300, 100, 40);
    const sf::Rect<int> &A3 = sf::IntRect(226, 300, 95, 40);
    const sf::Rect<int> &A4 = sf::IntRect(100, 400, 75, 50);
    const sf::Rect<int> &A5 = sf::IntRect(175, 400, 75, 50);
    const sf::Rect<int> &A6 = sf::IntRect(250, 400, 75, 50);

    //3 Questions that are in the game
    Question q1(1, "QBackgrounds.jpg", "arial.ttf");
    Question q2(2, "QBackgrounds.jpg", "arial.ttf");
    Question q3(3, "QBackgrounds.jpg", "arial.ttf");

    //two end screens which can appear
    End Win("win", "EndBack.jpg", "arial.ttf");
    End Lose("lose", "EndBack.jpg", "arial.ttf");

    //float 2d vector used in game loop
    sf::Vector2f checkDistance;

    while (window.isOpen())
    {   
        //polls for all possible events 
        while (window.pollEvent(event))
        {   
            if (event.type == sf::Event::EventType::Closed)
                window.close();
            //checking if up key is pressed to move player up
            if (event.type == sf::Event::EventType::KeyPressed)
                if (event.key.code == sf::Keyboard::Up) {
                    player.moveUp();
                }
            //same with left key
            if (event.type == sf::Event::EventType::KeyPressed)
                if (event.key.code == sf::Keyboard::Left) {
                    player.moveLeft();
                }
            //same with right key
            if (event.type == sf::Event::EventType::KeyPressed)
                if (event.key.code == sf::Keyboard::Right) {
                    player.moveRight();
                }
            //same with down key
            if (event.type == sf::Event::EventType::KeyPressed)
                if (event.key.code == sf::Keyboard::Down) {
                    player.moveDown();
                }
            //checking all mouse clicking events 
            if (event.type == sf::Event::MouseButtonPressed) {
                //checks if start button is clicked
                if (A1.contains(event.mouseButton.x, event.mouseButton.y) && start.getStart() == false) {
                    start.setStart(true);
                }
                //checks if replay button is pressed 
                else if (A2.contains(event.mouseButton.x, event.mouseButton.y) && (gameOver == 1 || loss == 1)) {
                    Win.setRestartFlag(true);
                    Lose.setRestartFlag(true);
                    gameOver = 0;
                    loss = 0;
                }
                //checks if end game button is pressed
                else if (A3.contains(event.mouseButton.x, event.mouseButton.y) && (gameOver == 1 || loss == 1)) {
                    gameOver = 0;
                    loss = 0;
                    window.close();
                    //exit
                }
                //checks if right answer is pressed
                else if(A4.contains(event.mouseButton.x, event.mouseButton.y) && questionFlag == 1) {
                    questionFlag = 0;
                    //if the it is the last question in the game, end game
                    if (back1.getFlag() == 1 && back2.getFlag() == 1 && back3.getFlag() == 1) {
                        gameOver = 1;
                    }
                }
                //checks if wrong button is pressed to end game
                else if(A5.contains(event.mouseButton.x, event.mouseButton.y) && questionFlag == 1) {
                    loss = 1;
                    questionFlag = 0;
                }
                //same as A5
                else if(A6.contains(event.mouseButton.x, event.mouseButton.y) && questionFlag == 1) {
                    loss = 1;
                    questionFlag = 0;
                }
            }
        }
        
        window.clear();

        //draws the start screen 
        if (start.getStart() == false) {
            start.draw(window);
        }
        
        //when in a question screen force player to stay at start point to avoid later issues
        if (questionFlag == 1) {
            player.setStart();
        }

        //if not in start screen or game over 
        if (start.getStart() == true && gameOver == 0) {
            //if one of the restart flags is shown, re initialize everything
            if (Win.getRestartFlag() == true || Lose.getRestartFlag() == true) {
                Win.setRestartFlag(false);
                Lose.setRestartFlag(false);
                initFlag = 0;
                back1.setFlag(0);
                back2.setFlag(0);
                back3.setFlag(0);
                player.setCollision(0);

            }

            //if initialize flag is 0 re initialize player
            if (initFlag == 0) {
                player.setStart();
                initFlag = 1;
            }

            //Background 1 display
            if (back1.getFlag() == 0 && questionFlag == 0) {
                back1.draw(window);

                r2Car1.draw(window);
                r2Car2.draw(window);
                r2Car3.draw(window);
                r2Car4.draw(window);
                r3Car1.draw(window);
                r3Car2.draw(window);
                b1Bike1.draw(window);
                b1Bike2.draw(window);
                r6Car1a.draw(window);
                r6Car2a.draw(window);
                r6Car3a.draw(window);
                r7Car1.draw(window);

                r2Car1.moveLeft(1.0f);
                r2Car2.moveLeft(1.0f);
                r2Car3.moveLeft(1.0f);
                r2Car4.moveLeft(1.0f);
                r3Car1.moveLeft(2.0f);
                r3Car2.moveLeft(2.0f);
                b1Bike1.moveRight(2.5f);
                b1Bike2.moveRight(2.5f);
                r6Car1a.moveRight(1.5f);
                r6Car2a.moveRight(1.5f);
                r6Car3a.moveRight(1.5f);
                r7Car1.moveRight(4.0f);

                player.checkCollision(r2Car1.getSprite());
                player.checkCollision(r2Car2.getSprite());
                player.checkCollision(r2Car3.getSprite());
                player.checkCollision(r2Car4.getSprite());
                player.checkCollision(r3Car1.getSprite());
                player.checkCollision(r3Car2.getSprite());
                player.checkCollision(b1Bike1.getSprite());
                player.checkCollision(b1Bike2.getSprite());
                player.checkCollision(r6Car1a.getSprite());
                player.checkCollision(r6Car2a.getSprite());
                player.checkCollision(r6Car3a.getSprite());
                player.checkCollision(r7Car1.getSprite());

                player.draw(window);

                if (player.getCollision() == 1) {
                    loss = 1;
                }
            }
            //q1 display
            else if (questionFlag == 1 && back1.getFlag() == 1 && back2.getFlag() == 0) {
                q1.draw(window);
            }
            //background 2 display
            else if (back1.getFlag() == 1 && back2.getFlag() == 0 && questionFlag == 0) {
                back2.draw(window);
                
                r1Car1.draw(window);
                r1Car2.draw(window);
                r2Car1.draw(window);
                r2Car2.draw(window);
                r2Car3.draw(window);
                r2Car4.draw(window);
                r3Car1.draw(window);
                r3Car2.draw(window);
                b1Bike1.draw(window);
                b1Bike2.draw(window);
                b2Bike1.draw(window);
                b2Bike2.draw(window);
                r5Car1.draw(window);
                r5Car2.draw(window);
                r6Car1a.draw(window);
                r6Car2a.draw(window);
                r6Car3a.draw(window);
                r7Car1.draw(window);

                r1Car1.moveRight(2.0f);
                r1Car2.moveRight(2.0f);
                r2Car1.moveLeft(2.0f);
                r2Car2.moveLeft(2.0f);
                r2Car3.moveLeft(2.0f);
                r2Car4.moveLeft(2.0f);
                r3Car1.moveLeft(3.0f);
                r3Car2.moveLeft(3.0f);
                b1Bike1.moveRight(4.0f);
                b1Bike2.moveRight(4.0f);
                b2Bike1.moveLeft(3.0f);
                b2Bike2.moveLeft(3.0f);
                r5Car1.moveRight(4.0f);
                r5Car2.moveRight(4.0f);
                r6Car1a.moveRight(2.5f);
                r6Car2a.moveRight(2.5f);
                r6Car3a.moveRight(2.5f);
                r7Car1.moveRight(5.0f);

                player.checkCollision(r1Car1.getSprite());
                player.checkCollision(r1Car2.getSprite());
                player.checkCollision(r2Car1.getSprite());
                player.checkCollision(r2Car2.getSprite());
                player.checkCollision(r2Car3.getSprite());
                player.checkCollision(r2Car4.getSprite());
                player.checkCollision(r3Car1.getSprite());
                player.checkCollision(r3Car2.getSprite());
                player.checkCollision(b1Bike1.getSprite());
                player.checkCollision(b1Bike2.getSprite());
                player.checkCollision(b2Bike1.getSprite());
                player.checkCollision(b2Bike2.getSprite());
                player.checkCollision(r5Car1.getSprite());
                player.checkCollision(r5Car2.getSprite());
                player.checkCollision(r6Car1a.getSprite());
                player.checkCollision(r6Car2a.getSprite());
                player.checkCollision(r6Car3a.getSprite());
                player.checkCollision(r7Car1.getSprite());

                player.draw(window);

                if (player.getCollision() == 1) {
                    loss = 1;
                }
            }
            //q2 display
            else if (questionFlag == 1 && back1.getFlag() == 1 && back2.getFlag() == 1 && back3.getFlag() == 0) {
                q2.draw(window);
            }
            //background 3 display
            else if (back1.getFlag() == 1 && back2.getFlag() == 1 && back3.getFlag() == 0 && questionFlag == 0) {
                back3.draw(window);

                r1Car1.draw(window);
                r1Car2.draw(window);
                r2Car1.draw(window);
                r2Car2.draw(window);
                r2Car3.draw(window);
                r2Car4.draw(window);
                r3Car1.draw(window);
                r3Car2.draw(window);
                r4Car1.draw(window);
                r4Car2.draw(window);
                r4Car3.draw(window);
                b1Bike1.draw(window);
                b1Bike2.draw(window);
                b2Bike1.draw(window);
                b2Bike2.draw(window);
                r5Car1.draw(window);
                r5Car2.draw(window);
                r6Car1a.draw(window);
                r6Car2a.draw(window);
                r6Car3a.draw(window);
                r6Car1b.draw(window);
                r6Car2b.draw(window);
                r6Car3b.draw(window);
                r7Car1.draw(window);

                r1Car1.moveRight(3.0f);
                r1Car2.moveRight(3.0f);
                r2Car1.moveLeft(3.0f);
                r2Car2.moveLeft(3.0f);
                r2Car3.moveLeft(3.0f);
                r2Car4.moveLeft(3.0f);
                r3Car1.moveLeft(4.0f);
                r3Car2.moveLeft(4.0f);
                r4Car1.moveLeft(5.0f);
                r4Car2.moveLeft(5.0f);
                r4Car3.moveLeft(5.0f);
                b1Bike1.moveRight(5.0f);
                b1Bike2.moveRight(5.0f);
                b2Bike1.moveLeft(4.0f);
                b2Bike2.moveLeft(4.0f);
                r5Car1.moveRight(5.0f);
                r5Car2.moveRight(5.0f);
                r6Car1a.moveRight(4.0f);
                r6Car2a.moveRight(4.0f);
                r6Car3a.moveRight(4.0f);
                r6Car1b.moveLeft(4.5f);
                r6Car2b.moveLeft(4.5f);
                r6Car3b.moveLeft(4.5f);
                r7Car1.moveRight(5.0f);

                player.checkCollision(r1Car1.getSprite());
                player.checkCollision(r1Car2.getSprite());
                player.checkCollision(r2Car1.getSprite());
                player.checkCollision(r2Car2.getSprite());
                player.checkCollision(r2Car3.getSprite());
                player.checkCollision(r2Car4.getSprite());
                player.checkCollision(r3Car1.getSprite());
                player.checkCollision(r3Car2.getSprite());
                player.checkCollision(r4Car1.getSprite());
                player.checkCollision(r4Car2.getSprite());
                player.checkCollision(r4Car3.getSprite());
                player.checkCollision(b1Bike1.getSprite());
                player.checkCollision(b1Bike2.getSprite());
                player.checkCollision(b2Bike1.getSprite());
                player.checkCollision(b2Bike2.getSprite());
                player.checkCollision(r5Car1.getSprite());
                player.checkCollision(r5Car2.getSprite());
                player.checkCollision(r6Car1a.getSprite());
                player.checkCollision(r6Car2a.getSprite());
                player.checkCollision(r6Car3a.getSprite());
                player.checkCollision(r6Car1b.getSprite());
                player.checkCollision(r6Car2b.getSprite());
                player.checkCollision(r6Car3b.getSprite());
                player.checkCollision(r7Car1.getSprite());

                player.draw(window);

                if (player.getCollision() == 1) {
                    loss = 1;
                }
            }
            //q3 display
            else if (back1.getFlag() == 1 && back2.getFlag() == 1 && back3.getFlag() == 1 && questionFlag == 1) {
                q3.draw(window);
            }

            //check how far the player is in the level, if they are at the end, throw a flag and move on to next question
            checkDistance = player.getPosition();
            if (checkDistance.y < 0) {
                if (back1.getFlag() == 0) {
                    back1.setFlag(1);
                    initFlag = 0;
                    questionFlag = 1;
                }
                else if (back2.getFlag() == 0) {
                    back2.setFlag(1);
                    initFlag = 0;
                    questionFlag = 1;
                }
                else if (back3.getFlag() == 0) {
                    back3.setFlag(1);
                    initFlag = 0;
                    questionFlag = 1;
                }
            }
        }

        //if the game is over, draw win display
        if (gameOver == 1) {
            Win.draw(window);
        }

        //if player lost, draw lose display
        if (loss == 1) {
            Lose.draw(window);
        }

        //display the window
        window.display();
       
    }

    return 0;
}
