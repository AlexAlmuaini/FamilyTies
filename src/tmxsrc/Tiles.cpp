//
// Created by AlexA on 3/10/2023.
//

#include "Tiles.h"
#include <iostream>

void Tiler::tilerInit()
{
  if(!map.load("Data/Room_1.tmx"))
  {
    std::cout << "Failed to load Tilemap";
  }

  if(!tileSpriteTexture.loadFromFile("Data/Tilemap/tilemap.png"))
  {
    std::cout << "Failed to load sprites";
  }
}
Tiler::Tiler() {}
