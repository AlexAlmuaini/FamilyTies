//
// Created by AlexA on 4/4/2023.
//

#include "PressurePlate.h"
PressurePlate::PressurePlate() {}
void PressurePlate::PPInit()
{
  pp_texture.loadFromFile("Data/Images/PressurePlate.png");
  pp_sprite.setTexture(pp_texture);
  pp_sprite.setScale(.04f,.04f);
}
