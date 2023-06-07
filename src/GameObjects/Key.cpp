//
// Created by gj2-betts on 24/03/2023.
//

#include "Key.h"

Key::Key()
{
}

const sf::Sprite& Key::getSprite() const
{
  return sprite;
}

void Key::setSprite(const sf::Sprite& sprite)
{
  Key::sprite = sprite;
}

void Key::setPosition(float a, float b)
{
  sprite.setPosition(a,b);
}

void Key::reset()
{
  sprite.setPosition(-100, -100);
}

bool Key::collisionCheck(sf::Sprite* object, sf::Sprite thing)
{
  float left_object = object->getPosition().x;
  float right_object = object->getPosition().x + object->getGlobalBounds().width;
  float top_object = object->getPosition().y;
  float bottom_object = object->getPosition().y +object->getGlobalBounds().height;

  float left_thing = thing.getPosition().x;
  float right_thing = thing.getPosition().x + thing.getGlobalBounds().width;
  float top_thing = thing.getPosition().y;
  float bottom_thing = thing.getPosition().y +thing.getGlobalBounds().height;

  if ((left_thing < right_object) && (right_thing > left_object) && (top_thing < bottom_object) && (bottom_thing > top_object))
  {
    return true;
  }
  return false;
}