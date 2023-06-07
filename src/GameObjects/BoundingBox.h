#pragma once

#include <SFML/Graphics.hpp>
#include "Vector2.h"

class BoundingBox
{
 public:
  BoundingBox();
  BoundingBox(sf::Sprite sprite);
  void manualBuild(float x, float y, float wid, float hei);

  Vector2 north_west = Vector2(0,0);
  Vector2 south_east = Vector2(0,0);

  float width;
  float height;

};
