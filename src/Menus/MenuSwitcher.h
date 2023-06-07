//
// Created by Steven on 17/03/2023.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "GameOver.h"

class MenuSwitcher {

public:
    MenuSwitcher(sf::RenderWindow& window);
    ~MenuSwitcher();

    bool init();
    void update(float dt);
    void render();

    void keyPressed(sf::Event event);
    void mouseClicked(sf::Event event);
    void mouseMoved(sf::Event event);

    enum StateEnum
    {
        mainMenuState,
        gamePlayState,
        gameOverState,
        pauseState
    };

    StateEnum current_state = mainMenuState;

    std::unique_ptr<MainMenu>mainMenu;
    std::unique_ptr<GameOver>gameOver;

private:
    sf::RenderWindow& window;
};
