//
// Created by Steven on 19/03/2023.
//

#include "GameOver.h"
#include <iostream>

GameOver::GameOver(sf::RenderWindow &window) : window(window) {}

GameOver::~GameOver() = default;


bool GameOver::init() {
//    if (!backgroundTexture.loadFromFile(""))
//        std::cout << "The Background didn't load in :( \n";
//
//    background.setTexture(backgroundTexture);

    if (!font.loadFromFile("Data/Fonts/Roboto/RobotoSlab-Bold.ttf"))
        std::cout << "The Font didn't load in :( \n";

    pageTitle.setFont(font);
    pageTitle.setString("Game Over");
    pageTitle.setCharacterSize(50);
    pageTitle.setFillColor(sf::Color(255, 0, 0));
    pageTitle.setPosition(
            window.getSize().x / 2 - pageTitle.getGlobalBounds().width / 2,
            100 - pageTitle.getGlobalBounds().height / 2);

    play.setFont(font);
    play.setString("Replay");
    play.setCharacterSize(50);
    play.setFillColor(sf::Color(255, 255, 255));
    play.setPosition(
            window.getSize().x / 2 - play.getGlobalBounds().width / 2,
            300 - play.getGlobalBounds().height / 2);

    quit.setFont(font);
    quit.setString("Quit");
    quit.setCharacterSize(50);
    quit.setFillColor(sf::Color(255, 255, 255));
    quit.setPosition(
            window.getSize().x / 2 - quit.getGlobalBounds().width / 2,
            450 - quit.getGlobalBounds().height / 2);

    clicked = false;
//    timer = 0;

    return true;
}

void GameOver::update(float dt)
{

}

void GameOver::render() {
    window.draw(background);
    window.draw(pageTitle);
    window.draw(play);
    window.draw(quit);
}

//void GameOver::keyPressed(sf::Event event) {
//    if (event.key.code == sf::Keyboard::Up){
//        isPlay = true;
//        play.setFillColor(sf::Color(255, 255, 255));
//        quit.setFillColor(sf::Color(255, 0, 0));
//    }
//
//    else if(event.key.code == sf::Keyboard::Down) {
//        isPlay = false;
//        play.setFillColor(sf::Color(255, 0, 0));
//        quit.setFillColor(sf::Color(255, 255, 255));
//    }
//}


void GameOver::mouseClicked(sf::Event event)
{
    sf::Vector2i click = sf::Mouse::getPosition(window);

    sf::FloatRect playBox = play.getGlobalBounds();
    sf::FloatRect quitBox = quit.getGlobalBounds();
    sf::FloatRect titleBox = pageTitle.getGlobalBounds();
    ////might leave in some cheeky title click easteregg - set name back to bingus sim or something

    if (playBox.contains(click.x, click.y)){
        clicked = true;
    }

    else if (quitBox.contains(click.x, click.y)){
        window.close();
    }

    else if (titleBox.contains(click.x, click.y)){
        pageTitle.setString("Bingus Simulator");
        pageTitle.setPosition(
                window.getSize().x / 2 - pageTitle.getGlobalBounds().width / 2,
                100 - pageTitle.getGlobalBounds().height / 2);
    }
}

void GameOver::mouseMoved(sf::Event event)
{
    sf::Vector2i mouse = sf::Mouse::getPosition(window);

    sf::FloatRect playBox = play.getGlobalBounds();
    sf::FloatRect quitBox = quit.getGlobalBounds();

    if(playBox.contains(mouse.x, mouse.y))
    {
        play.setFillColor(sf::Color(255, 0, 0));
        quit.setFillColor(sf::Color(255, 255, 255));
    }

    else if(quitBox.contains(mouse.x, mouse.y))
    {
        play.setFillColor(sf::Color(255, 255, 255));
        quit.setFillColor(sf::Color(255, 0, 0));
    }
}
