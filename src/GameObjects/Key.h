//
// Created by gj2-betts on 24/03/2023.
//

#ifndef SFMLGAME_KEY_H
#define SFMLGAME_KEY_H

#include <SFML/Graphics.hpp>

class Key
{
 public:
  Key();
  const sf::Sprite& getSprite() const;
  void setSprite(const sf::Sprite& sprite);
  void setPosition(float a, float b);
  void reset();
  bool collisionCheck(sf::Sprite *object, sf::Sprite thing);
  sf::Sprite sprite;
  sf::Texture texture;


 private:


};

#endif // SFMLGAME_KEY_H
