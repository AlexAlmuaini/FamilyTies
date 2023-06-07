//
// Created by Rosa Kay on 21/03/2023.
//

#ifndef SFMLGAME_PLAYERMOVEMENT_H
#define SFMLGAME_PLAYERMOVEMENT_H

#include <SFML/Graphics.hpp>
#include "player.h"

class playerMovement
{
 public:
  void playerClamping(int playerNo, float dt, player player1, player player2, sf::CircleShape player1Rad, sf::CircleShape player2Rad);
  void move(player _player1, player _player2, sf::CircleShape p1Rad, sf::CircleShape p2Rad, sf::Vector2f vel1,  sf::Vector2f vel2);
  void setPosition( int playerNo, float dt, player player1, player player2, sf::CircleShape player1Rad, sf::CircleShape player2Rad);
  void setVelocity(sf::Vector2f _velocity, sf::Vector2f _velocity2);
  void checkClamp(float dt, player player1, player player2, sf::CircleShape p1Rad, sf::CircleShape p2Rad);
  sf::Vector2f p1vel {0,0};
  sf::Vector2f getPos(sf::CircleShape _radius);
  sf::Vector2f getVelocity(int playerNo);
  bool clamped;
  //sf::Vector2f p1pos;
  //sf::Vector2f p2pos;
  //sf::Vector2f clampVel;

 private:
  float radius = 80.0f;
  //float speed = 400;

  sf::Vector2f velocity1 {0,0};
  sf::Vector2f velocity2 {0,0};



};

#endif // SFMLGAME_PLAYERMOVEMENT_H
