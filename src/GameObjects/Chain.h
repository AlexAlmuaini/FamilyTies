//
// Created by Rosa Kay on 26/03/2023.
//

#ifndef SFMLGAME_CHAIN_H
#define SFMLGAME_CHAIN_H

#include <SFML/Graphics.hpp>
#include "player.h"

class Chain
{
 public:
  Chain();
  void init(player player1, player player2);
  sf::VertexArray getChainArray();

  sf::VertexArray chain;


};

#endif // SFMLGAME_CHAIN_H
