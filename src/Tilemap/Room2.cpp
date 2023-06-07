//
// Created by AlexA on 3/27/2023.
//

#include "Room2.h"
#include <iostream>

Room2::Room2() {}

void Room2::Room2Init()
{
  // loads map file
  if (!map.load("Data/Room_2.tmx"))
  {
    std::cout << "Failed to load Tilemap";
  }

  // loads map tile sheet
  if (!tileMap.loadFromFile("Data/Tilemap/tilemap_HighContrast.png"))
  {
    std::cout << "Failed to load sprites";
  }

  if (!decorTileMap.loadFromFile("Data/Tilesheets/roguelikeIndoor_transparent.png"))
  {
    std::cout << "Failed to load sprites";
  }

  const auto& layers     = map.getLayers();
  const auto Floorlayer  = layers[0]->getLayerAs<tmx::TileLayer>();
  const auto& Floortiles = Floorlayer.getTiles();

  const auto wallLayer  = layers[1]->getLayerAs<tmx::TileLayer>();
  const auto& wallTiles = wallLayer.getTiles();

  const auto decorLayer  = layers[2]->getLayerAs<tmx::TileLayer>();
  const auto& decorTiles = decorLayer.getTiles();

  int tilesAcross = 20;
  // Assigns textures to floor & open door tiles (*￣3￣)╭
  for (int j = 0; j < Floortiles.size(); j++)
  {
    idx = j / tilesAcross;
    idy = j % tilesAcross;
    Floortile[idx][idy].tileSprite.setScale(5, 5);
    Floortile[idx][idy].tileSprite.setTexture(tileMap);
    Floortile[idx][idy].tileSprite.setPosition(idy * 16 * 5, idx * 16 * 5);
    Floortile[idx][idy].tileID = Floortiles[j].ID;

    int x = ((int(Floortiles[j].ID) % 12) * 17) - 17;
    // this works
    int y = ((int(Floortiles[j].ID) / 12) * 17);
    if (x < 0)
    {
      x = 187;
    }
    if (y == 34)
    {
      y = 17;
    }
    Floortile[idx][idy].tileSprite.setTextureRect(sf::IntRect(x, y, 16, 16));

    // const auto layer3 = layers[2]->getLayerAs<tmx::ObjectGroup>();
    // const auto& tiles3 = layer3.getObjects();
  }
  for (int j = 0; j < decorTiles.size(); j++)
  {
    idx = j / tilesAcross;
    idy = j % tilesAcross;
    Decortile[idx][idy].tileSprite.setScale(5, 5);
    Decortile[idx][idy].tileSprite.setTexture(decorTileMap);
    Decortile[idx][idy].tileSprite.setPosition(idy * 16 * 5, idx * 16 * 5);
    Decortile[idx][idy].tileID = decorTiles[j].ID - 132;

    int x = ((int(decorTiles[j].ID - 132) % 27) * 17) - 17;

    if (x < 0)
    {
      x = 187;
    }
    // this works
    int y = ((int(decorTiles[j].ID - 132) / 27) * 17);

    // hard coded some tiles because the math brakes on the end row
    if (decorTiles[j].ID == 402)
    {
      x = 442;
      y = 153;
    }
    if (decorTiles[j].ID == 375)
    {
      x = 442;
      y = 136;
    }

    Decortile[idx][idy].tileSprite.setTextureRect(sf::IntRect(x, y, 16, 16));
  }

  // Assigns textures Wall till loading code ~ just loads the perimeter grey bricks （￣︶￣）↗　
  for (int j = 0; j < wallTiles.size(); j++)
  {
    idx = j / tilesAcross;
    idy = j % tilesAcross;
    Walltile[idx][idy].tileSprite.setScale(5, 5);
    Walltile[idx][idy].tileSprite.setTexture(tileMap);
    Walltile[idx][idy].tileSprite.setPosition(idy * 16 * 5, idx * 16 * 5);
    Walltile[idx][idy].tileID = wallTiles[j].ID;

    int x = ((int(wallTiles[j].ID) % 12) * 17) - 17;
    // this works
    int y = ((int(wallTiles[j].ID) / 12) * 17);
    if(x < 0)
    {
      x = 187;
    }
    if(y == 34)
    {
      y = 17;
    }

    if(wallTiles[j].ID != 0 && wallTiles[j].ID != 48)
    {
      Walltile[idx][idy].tileSprite.setTextureRect(sf::IntRect(x,y,16,16));
    }
    else if (wallTiles[j].ID == 48)
    {
      Walltile[idx][idy].tileSprite.setTextureRect(sf::IntRect(187,51,16,16));
    }
    else
    {
      Walltile[idx][idy].tileSprite.setTextureRect(sf::IntRect(0,0,0,0));
    }

  }
}

void Room2::OpenDoor()
{
  const auto& layers = map.getLayers();
  const auto openDoorLayer = layers[3]->getLayerAs<tmx::TileLayer>();
  const auto& openDoorTiles = openDoorLayer.getTiles();

  for(int j = 0; j < openDoorTiles.size(); j++)
  {
    idx = j / 20;
    idy = j % 20;
    Doortile[idx][idy].tileSprite.setScale(5,5);
    Doortile[idx][idy].tileSprite.setTexture(tileMap);
    Doortile[idx][idy].tileSprite.setPosition(idy *16*5, idx *16*5);
    Doortile[idx][idy].tileID = openDoorTiles[j].ID;

    int x = ((int(openDoorTiles[j].ID)%12)*17) - 17;
    //this works
    int y = ((int(openDoorTiles[j].ID)/12)*17);
    if(x < 0)
    {
      x = 187;
    }
    if(y == 34)
    {
      y = 17;
    }

    if(openDoorTiles[j].ID != 0)
    {
      Doortile[idx][idy].tileSprite.setTextureRect(sf::IntRect(x,y,16,16));
    }
    else
    {
      Doortile[idx][idy].tileSprite.setTextureRect(sf::IntRect(0,0,0,0));
    }

  }
}