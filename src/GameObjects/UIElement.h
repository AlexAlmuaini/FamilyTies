//
// Created by Steven on 18/04/2023.
//

#ifndef SFMLGAME_UIELEMENT_H
#define SFMLGAME_UIELEMENT_H

#include <SFML/Graphics.hpp>

class UIElement
{
 public:
  UIElement();
  void init(int input);
  void update(float dt);
  void render(sf::RenderWindow& window);

  void setPosition(float x, float y);
  void setScale(float x, float y);

  sf::Clock animationClock;

  sf::Sprite sprite;
  sf::Texture texture;
  sf::IntRect textureRectangle;

 private:

};

#endif // SFMLGAME_UIELEMENT_H
