//
// Created by gj2-betts on 24/03/2023.
//

#include "Gameobject2.h"
#include <iostream>

Gameobject2::Gameobject2()
{
  sprite = new sf::Sprite();
}

Gameobject2::~Gameobject2()
{
  if (sprite != nullptr)
  {
    delete sprite;
    sprite = nullptr;
  }
}

bool Gameobject2::initialiseSprite(sf::Texture& texture, std::string filename)
{
  if (!texture.loadFromFile(filename))
  {
    std::cout << "Texture " << filename << "did not load \n";
    return false;
  }
  else
  {
    sprite->setTexture(texture);
    return true;
  }
}

sf::Sprite * Gameobject2::getSprite()
{
  return sprite;
}
