//
// Created by gj2-betts on 24/03/2023.
//

#ifndef SFMLGAME_GAMEOBJECT2_H
#define SFMLGAME_GAMEOBJECT2_H

#include <SFML/Graphics.hpp>

class Gameobject2
{
 public:
  Gameobject2();
  ~Gameobject2();

  bool initialiseSprite(sf::Texture &texture,std::string filename);
  sf::Sprite* getSprite();
  bool visibility = false;

 private:
  sf::Sprite* sprite = nullptr;
};

#endif // SFMLGAME_GAMEOBJECT2_H
