//
// Created by Steven on 19/03/2023.
//

#pragma once
#include <SFML/Graphics.hpp>

class GameOver
{
    public:
        GameOver(sf::RenderWindow &window);
        ~GameOver();

        bool init();
        void update(float dt);
        void render();

//      void keyPressed(sf::Event event);
        void mouseClicked(sf::Event event);
        void mouseMoved(sf::Event event);

        bool clicked;
        float timer;
        float alpha = 255;

    private:
        sf::RenderWindow& window;

        sf::Font font;
        sf::Text pageTitle;
        sf::Text play;
        sf::Text quit;

        sf::Sprite background;
        sf::Texture backgroundTexture;
};
