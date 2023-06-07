//
// Created by AlexA on 3/10/2023.
//

#ifndef SFMLGAME_TILES_H
#define SFMLGAME_TILES_H
#include <SFML/Graphics.hpp>
#include <tmxlite/Map.hpp>
#include <tmxlite/Layer.hpp>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/ObjectGroup.hpp>

class Tiler
{
 public:
  Tiler();
  void tilerInit();
  sf::Sprite tileSprite;
  sf::Texture tileSpriteTexture;
  int tileID;
  tmx::Map map;
};

#endif // SFMLGAME_TILES_H
