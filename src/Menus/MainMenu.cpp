//
// Created by Steven on 10/03/2023.
//

#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu(sf::RenderWindow &window) : window(window) {}

MainMenu::~MainMenu() = default;


bool MainMenu::init() {
    if (!backgroundTexture.loadFromFile("Data/sprites/MenuBackground.png"))
        std::cout << "The Background didn't load in :( \n";

    background.setTexture(backgroundTexture);

    if (!font.loadFromFile("Data/Fonts/Roboto/RobotoSlab-Bold.ttf"))
        std::cout << "The Font didn't load in :( \n";

    pageTitle.setFont(font);
    pageTitle.setString("Family Ties");
    pageTitle.setCharacterSize(100);
    pageTitle.setFillColor(sf::Color(200, 50, 0));
    pageTitle.setPosition(
            window.getSize().x / 2 - pageTitle.getGlobalBounds().width / 2,
            300 - pageTitle.getGlobalBounds().height / 2);

    play.setFont(font);
    play.setString("Play");
    play.setCharacterSize(75);
    play.setFillColor(sf::Color(255, 255, 255));
    play.setPosition(
            window.getSize().x / 2 - play.getGlobalBounds().width / 2,
            500 - play.getGlobalBounds().height / 2);

    quit.setFont(font);
    quit.setString("Quit");
    quit.setCharacterSize(75);
    quit.setFillColor(sf::Color(255, 255, 255));
    quit.setPosition(
            window.getSize().x / 2 - quit.getGlobalBounds().width / 2,
            650 - quit.getGlobalBounds().height / 2);

    clicked = false;
//    timer = 0;

    return true;
}

void MainMenu::update(float dt)
{

}

void MainMenu::render() {
    window.draw(background);
    window.draw(pageTitle);
    window.draw(play);
    window.draw(quit);
}

//void MainMenu::keyPressed(sf::Event event) {
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


void MainMenu::mouseClicked(sf::Event event)
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

void MainMenu::mouseMoved(sf::Event event)
{
    sf::Vector2i mouse = sf::Mouse::getPosition(window);

    sf::FloatRect playBox = play.getGlobalBounds();
    sf::FloatRect quitBox = quit.getGlobalBounds();

    if(playBox.contains(mouse.x, mouse.y))
    {
        play.setFillColor(sf::Color(200, 50, 0));
        quit.setFillColor(sf::Color(255, 255, 255));
    }

    else if(quitBox.contains(mouse.x, mouse.y))
    {
        play.setFillColor(sf::Color(255, 255, 255));
        quit.setFillColor(sf::Color(200, 50, 0));
    }
}


