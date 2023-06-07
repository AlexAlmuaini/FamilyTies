//
// Created by Steven on 17/03/2023.
//

#include "MenuSwitcher.h"

MenuSwitcher::MenuSwitcher(sf::RenderWindow &window) : window(window) {
    mainMenu = std::make_unique<MainMenu>(window);
    gameOver = std::make_unique<GameOver>(window);
}

MenuSwitcher::~MenuSwitcher() = default;

bool MenuSwitcher::init() {
    switch (current_state)
    {
        case mainMenuState:
        {
            mainMenu->init();
        }
        break;

        case gamePlayState: {}
        break;

        case gameOverState:
        {
            gameOver->init();
        }
        break;
    }
    return true;
}

void MenuSwitcher::update(float dt) {
    switch (current_state) {
        case mainMenuState:
        {
            mainMenu->update(dt);
        }
        break;

        case gamePlayState: {}
        break;

        case gameOverState:
        {
            gameOver->update(dt);
        }
        break;
    }
}

void MenuSwitcher::render() {
    switch (current_state) {
        case mainMenuState:
        {
            mainMenu->render();
        }
        break;

        case gamePlayState: {}
        break;

        case gameOverState:
        {
            gameOver->render();
        }
        break;
    }
}
/*
void MenuSwitcher::keyPressed(sf::Event event) {
    switch (current_state) {
        case mainMenuState:
        {
            mainMenu->keyPressed(event);

            if (event.key.code == sf::Keyboard::Enter)
            {
                if (mainMenu->isPlay)
                {
                    current_state = gamePlayState;
                    //gameReset();
                }

                else
                {
                    window.close();
                }
            }
        }
        break;

        case gamePlayState: {}
        break;
    }
}
*/

void MenuSwitcher::mouseClicked(sf::Event event) {
    switch (current_state) {
        case mainMenuState:
        {
          mainMenu->mouseClicked(event);
          if (mainMenu->clicked)
          {
            current_state = gamePlayState;
          }
        }
        break;

        case gamePlayState: {}
        break;

        case gameOverState:
        {
            gameOver->mouseClicked(event);
            if (gameOver->clicked)
            {
                current_state = gamePlayState;
            }
        }
        break;
    }
}

void MenuSwitcher::mouseMoved(sf::Event event) {
    switch (current_state) {
        case mainMenuState:
        {
            mainMenu->mouseMoved(event);
        }
        break;

        case gamePlayState: {}
        break;

        case gameOverState:
        {
            gameOver->mouseMoved(event);
        }
        break;
    }
}