//
// Created by AlexA on 3/17/2023.
//

#ifndef SFMLGAME_ROOM1_H
#define SFMLGAME_ROOM1_H

#include "../tmxsrc/Tiles.h"

class Room1
{
 public:
  Room1();
  void Room1Init();
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

#endif // SFMLGAME_ROOM1_H
