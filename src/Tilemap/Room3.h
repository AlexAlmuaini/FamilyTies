//
// Created by AlexA on 4/5/2023.
//

#ifndef SFMLGAME_ROOM3_H
#define SFMLGAME_ROOM3_H

#include "../tmxsrc/Tiles.h"

class Room3
{
 public:
  Room3();
  void Room3Init();
  void OpenDoor();
  Tiler Walltile[13][20];
  Tiler Floortile[13][20];
  Tiler Decortile[13][20];
  Tiler Doortile[13][20];

 private:
  tmx::Map map;
  sf::Texture tileMap;
  sf::Texture decorTileMap;
  int idx = 0, idy = 0;
};

#endif // SFMLGAME_ROOM3_H
