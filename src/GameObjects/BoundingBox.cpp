#include "BoundingBox.h"

BoundingBox::BoundingBox(sf::Sprite sprite)
{
  width = sprite.getGlobalBounds().width;
  height = sprite.getGlobalBounds().height;

  north_west = Vector2(sprite.getPosition().x, sprite.getPosition().y);
  south_east = Vector2(north_west.x + width, north_west.y + height);
}

void BoundingBox::manualBuild(float x, float y, float wid, float hei)
{
  width = wid;
  height = hei;

  north_west = Vector2(x,y);
  south_east = Vector2(north_west.x + width, north_west.y + height);
}
BoundingBox::BoundingBox() {}
