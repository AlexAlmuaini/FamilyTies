//
// Created by Rosa Kay on 26/03/2023.
//

#include "Chain.h"

Chain::Chain()
{
  chain.setPrimitiveType(sf::Quads);
  chain.resize(4);
}

void Chain::init(player player1, player player2)
{
  chain[0].position= sf::Vector2f(player1.getPosition().x, player1.getPosition().y + player1.getGlobalBounds().height);
  chain[1].position = sf::Vector2f(player1.getPosition().x + 5, player1.getPosition().y + player1.getGlobalBounds().height);
  chain[2].position = sf::Vector2f(player2.getPosition().x, player2.getPosition().y + player2.getGlobalBounds().height);
  chain[3].position = sf::Vector2f(player2.getPosition().x + 5, player2.getPosition().y + player2.getGlobalBounds().height);
}

sf::VertexArray Chain::getChainArray()
{
  return chain;
}

