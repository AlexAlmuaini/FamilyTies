//
// Created by Rosa Kay on 21/03/2023.
//

#include "playerMovement.h"
#include <iostream>
#include <cmath>

/*void playerMovement::setPosition(int playerNo, float dt, player player1, player player2, sf::CircleShape player1Rad, sf::CircleShape player2Rad)
{
  //checkClamp( dt,  player1,  player2,  player1Rad, player2Rad);
  //player1.setPosition(player1Rad.getPosition().x + (player1Rad.getRadius()/2), player1Rad.getPosition().y + (player1Rad.getRadius()/2));
  //player2.setPosition(player2Rad.getPosition().x + (player2Rad.getRadius()/2), player2Rad.getPosition().y + (player1Rad.getRadius()/2));
  /// Player 1 Movement
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
  {
    player1.setVelocity({0.0f, -(dt * speed)});
    //velocity1 = {0.0f, -(dt * speed)};
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
  {
    player1.setVelocity({0.0f, (dt * speed)});
    //velocity1 = {0.0f, (dt * speed)};
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
  {
    player1.setVelocity({(dt * speed), 0.0f});
    //velocity1 = {(dt * speed), 0.0f};
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
  {
    player1.setVelocity({-(dt * speed), 0.0f});
    //velocity1 = {-(dt * speed), 0.0f};
  }

  /// Player 2 Movement
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    player2.setVelocity({0.0f, - (dt * speed)});
    //velocity2 = {0.0f, -(dt * speed)};
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    player2.setVelocity({0.0f, (dt * speed)});
    //velocity2 = {0.0f, (dt * speed)};
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    player2.setVelocity({(dt * speed), 0.0f});
    //velocity2 = {(dt * speed), 0.0f};
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    player2.setVelocity({-(dt * speed), 0.0f});
    //velocity2 = {-(dt * speed), 0.0f};
  }
  else
    velocity1 = {0,0};
    velocity2 = {0,0};

  setVelocity(player1.getVelocity(), player2.getVelocity());

  //move(player1, player2, player1Rad, player2Rad, player1.getVelocity(), player2.getVelocity());

  //_player.setPosition(x,y);
}*/

void playerMovement::playerClamping(int playerNo, float dt, player player1, player player2, sf::CircleShape player1Rad, sf::CircleShape player2Rad)
{
  player1.setPosition(player1Rad.getPosition().x + (player1Rad.getRadius()/2),player1Rad.getPosition().y + (player1Rad.getRadius()/2));
  player2.setPosition(player2Rad.getPosition().x + (player2Rad.getRadius()/2),player2Rad.getPosition().y + (player2Rad.getRadius()/2));

  ///Player1 Movement
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
  {
    player1.setVelocity({0.0f, - (dt * player1.getSpeed())});
//    player1.textureRectangle.top = player1.texture.getSize().y / 6 * 2;
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
  {
    player1.setVelocity({0.0f, (dt * player1.getSpeed())});
    //player1.textureRectangle.top = player1.texture.getSize().y / 6 * 0;
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
  {
    player1.setVelocity({(dt * player1.getSpeed()), 0.0f});
    //player1.textureRectangle.top = player1.texture.getSize().y / 6 * 1;
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
  {
    player1.setVelocity({-(dt * player1.getSpeed()), 0.0f});
    //player1.textureRectangle.top = player1.texture.getSize().y / 6 * 1;
    //player1.sprite.setScale(-4,4);
  }

  else
    player1.setVelocity({0,0});


  ///Player2 Movement
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    player2.setVelocity({0.0f, - (dt * player2.getSpeed())});
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    player2.setVelocity({0.0f, (dt * player2.getSpeed())});
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    player2.setVelocity({(dt * player2.getSpeed()), 0.0f});
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    player2.setVelocity({-(dt * player2.getSpeed()), 0.0f});
  }
  else
    player2.setVelocity({0,0});


  /// player movement normal if not clamped
  if(!clamped)
  {
    player1Rad.move(player1.getVelocity());
    player2Rad.move(player2.getVelocity());
  }

  /// if players are clamped, set new velocity based on player1 and player2 velocity
  if(clamped)
  {
    sf::Vector2f clampVel;
    clampVel.x = player1.getVelocity().x + player2.getVelocity().x;
    clampVel.y = player1.getVelocity().y + player2.getVelocity().y;

    if(clampVel.x == 0)
    {
      player1.setVelocity({0,player1.getVelocity().y});
      player2.setVelocity({0,player2.getVelocity().y});
    }

    if(clampVel.x > 0)
    {
      clampVel.x = 10;
    }
    if(clampVel.x < 0)
    {
      clampVel.x = -10;
    }

    if(clampVel.y == 0)
    {
      player1.setVelocity({player1.getVelocity().x,0});
      player2.setVelocity({player2.getVelocity().x,0});
    }

    if(clampVel.y > 0)
    {
      clampVel.y = 10;
    }
    if(clampVel.y < 0)
    {
      clampVel.y = -10;
    }
    player1Rad.move(clampVel);
    player2Rad.move(clampVel);
  }

  /// check if clamped

  sf::FloatRect p1 = player1Rad.getGlobalBounds();
  sf::FloatRect p2 = player2Rad.getGlobalBounds();

  float p1x = player1Rad.getPosition().x;
  float p1y = player1Rad.getPosition().y;
  float p2x = player2Rad.getPosition().x;
  float p2y = player2Rad.getPosition().y;

  float dx = (player1Rad.getPosition().x + (p1.width/2)) - (player2Rad.getPosition().x + p2.width/2);
  float dy = (player1Rad.getPosition().y + (p1.height/2)) - (player2Rad.getPosition().y + (p2.height/2));
  float distance = std::sqrt((dx * dx) + (dy * dy));
  float overlap = 0.5f * (distance - player1Rad.getRadius() - player2Rad.getRadius());

  if(distance <= (p1.width/2) + (p2.width/2))
  {
    //std::cout << "Not clamped" << std::endl;
    clamped = false;
    //const auto layer3 = layers[2]->getLayerAs<tmx::ObjectGroup>();
    //const auto& tiles3 = layer3.getObjects();
  }

  else
  {
    //std::cout << "Clamped" << std::endl;
    clamped = true;

    sf::Vector2f p1pos = player1Rad.getPosition();
    sf::Vector2f p2pos = player2Rad.getPosition();

    p1pos.x -= overlap * (p1x - p2x) / distance;
    p1pos.y -= overlap * (p1y - p2y) / distance;

    p2pos.x += overlap * (p1x - p2x) / distance;
    p2pos.y += overlap * (p1y - p2y) / distance;

    player1Rad.setPosition(p1pos);
    player2Rad.setPosition(p2pos);
    clamped = false;
  }
}

/*void playerMovement::move(player player1, player player2, sf::CircleShape player1Rad, sf::CircleShape player2Rad, sf::Vector2f vel1, sf::Vector2f vel2)
{
  if(!clamped)
  {
    //std::cout << "not clamped" << std::endl;
    //_radius.move(vel);
    player1Rad.move(vel1);
    player2Rad.move(vel2);
  }

  if(clamped)
  {
    clampVel.x = player1.getVelocity().x + player2.getVelocity().x;
    clampVel.y = player1.getVelocity().y + player2.getVelocity().y;

    if(clampVel.x == 0)
    {
      player1.setVelocity({0,player1.getVelocity().y});
      player2.setVelocity({0,player2.getVelocity().y});
    }

    if(clampVel.x > 0)
    {
      clampVel.x = 10;
    }
    if(clampVel.x < 0)
    {
      clampVel.x = -10;
    }

    if(clampVel.y == 0)
    {
      player1.setVelocity({player1.getVelocity().x,0});
      player2.setVelocity({player2.getVelocity().x,0});
    }

    if(clampVel.y > 0)
    {
      clampVel.y = 10;
    }
    if(clampVel.y < 0)
    {
      clampVel.y = -10;
    }
    //player1Rad.move(clampVel);
    //player2Rad.move(clampVel);
  }
  
  //_player.setPosition();
}

/*void playerMovement::checkClamp(float dt, player player1, player player2, sf::CircleShape p1Rad, sf::CircleShape p2Rad)
{
  sf::FloatRect p1 = p1Rad.getGlobalBounds();
  sf::FloatRect p2 = p2Rad.getGlobalBounds();

  float p1x = p1Rad.getPosition().x;
  float p1y = p1Rad.getPosition().y;
  float p2x = p2Rad.getPosition().x;
  float p2y = p2Rad.getPosition().y;

  float dx = (p1Rad.getPosition().x + (p1.width/2)) - (p2Rad.getPosition().x + p2.width/2);
  float dy = (p1Rad.getPosition().y + (p1.height/2)) - (p2Rad.getPosition().y + (p2.height/2));
  float distance = std::sqrt((dx * dx) + (dy * dy));
  float overlap = 0.5f * (distance - p1Rad.getRadius() - p2Rad.getRadius());
  if (distance <= (p1.width / 2) + (p2.width / 2))
  {
    clamped = false;
  }
  else
  {
    clamped = true;

    p1pos = p1Rad.getPosition();
    p2pos = p2Rad.getPosition();

    p1pos.x -= overlap * (p1x - p2x) / distance;
    p1pos.y -= overlap * (p1y - p2y) / distance;

    p2pos.x += overlap * (p1x - p2x) / distance;
    p2pos.y += overlap * (p1x - p2x) / distance;

    //p1Rad.setPosition(p1pos);
    //p2Rad.setPosition(p2pos);

    //clamped = false;
  }
}*/

/*void playerMovement::setVelocity(sf::Vector2f _velocity, sf::Vector2f _velocity2)
{
  velocity1 = _velocity;
  velocity2 = _velocity2;
}

sf::Vector2f playerMovement::getPos(sf::CircleShape _radius)
{
  sf::Vector2f pos = {_radius.getPosition().x + (_radius.getRadius()/2), _radius.getPosition().y + (_radius.getRadius()/2)};
  return pos;
}

sf::Vector2f playerMovement::getVelocity(int playerNo)
{
  //std::cout << velocity.x << " " << velocity.y << std::endl;
  if (playerNo == 1)
  {
    return velocity1;
  }
  else
  {
    return velocity2;
  }
}*/
