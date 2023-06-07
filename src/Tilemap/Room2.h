//
// Created by AlexA on 3/27/2023.
//

#ifndef SFMLGAME_ROOM2_H
#define SFMLGAME_ROOM2_H

#include "../tmxsrc/Tiles.h"

class Room2
{
 public:
  Room2();
  void Room2Init();
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

#endif // SFMLGAME_ROOM2_H
