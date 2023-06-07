//
// Created by AlexA on 4/4/2023.
//

#ifndef SFMLGAME_PRESSUREPLATE_H
#define SFMLGAME_PRESSUREPLATE_H
#include <SFML/Graphics.hpp>

class PressurePlate
{
 public:
  PressurePlate();
  void PPInit();
  sf::Sprite pp_sprite;
  bool active = false;

 private:
  sf::Texture pp_texture;
};

#endif // SFMLGAME_PRESSUREPLATE_H
