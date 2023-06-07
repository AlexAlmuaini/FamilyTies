#include "Box.h"
#include <iostream>

Box::Box()
{
  init();
}

bool Box::init()
{
  initialiseSprite("Data/Images/padlock.png");
  damage = 0;
  visible = true;
  update_overlay();
  crack.setScale(4,4);
  setPosition(768,32);
  setScale(4,4);
  return true;
}

void Box::update_overlay()
{
  crack_texture.loadFromFile("Data/Images/destroy_stage_" + std::to_string(damage) +".png");
  crack.setTexture(crack_texture);
  crack.setPosition(sprite.getPosition());
}
void Box::hit(int dmg)
{
  if (visible)
  {
    damage += 1;
    if (damage >= 10)
    {
      despawn();
    }
    else
    {
      update_overlay();
    }
  }
}
bool Box::despawn()
{
  visible = false;
  damage = 12;
  setPosition(-1000,-1000);
  crack.setPosition(-1000,-1000);
  // deconstructor goes here but not made yet
  if (has_key)
  {
    return true;
  }
  return false;
}
void Box::update(float dt) {}
