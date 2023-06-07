//
// Created by AlexA on 4/21/2023.
//

#ifndef SFMLGAME_ROOM4_H

#define SFMLGAME_ROOM4_H
#include "../tmxsrc/Tiles.h"

class Room4
{
 public:
  Room4();
  void Room4Init();
  Tiler Walltile[13][20];
  Tiler Floortile[13][20];
  Tiler Decortile[13][20];

 private:
  tmx::Map map;
  sf::Texture tileMap;
  sf::Texture decorTileMap;
  int idx = 0, idy = 0;
};

#endif // SFMLGAME_ROOM4_H
