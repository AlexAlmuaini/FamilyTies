#include "player.h"
#include <iostream>

player::player() {}

void player::init(int input)
{
  if (input == 1)
  {
    texture.loadFromFile("Data/sprites/characters/PLAYER1.png");
  }
  else if (input == 2)
  {
    texture.loadFromFile("Data/sprites/characters/PLAYER2.png");
  }

  sprite.setTexture(texture);
  sprite.setOrigin(6.5, 0);
  textureRectangle = sf::IntRect(0,texture.getSize().y / 3,texture.getSize().x / 6 ,texture.getSize().y / 3);
  sprite.setTextureRect(textureRectangle);


  sprite.setScale(scale,scale);
  sprite.setPosition(200 * input, 400);
}

void player::update(float dt)
{
  if (animationClock.getElapsedTime().asSeconds() > 0.2)
  {
    textureRectangle.left += texture.getSize().x / 6;

    if (textureRectangle.left > texture.getSize().x / 6 * 5)
    {
      textureRectangle.left = 0;
    }

    sprite.setTextureRect(textureRectangle);
    animationClock.restart();
  }
}

void player::render(sf::RenderWindow& window, sf::Shader* shader)
{
  //shader->setUniform("hasTexture", true);
  //shader->setUniform("lightPos", this->getCenter());
  window.draw(sprite, shader);
}

void player::move(sf::Vector2f vel)
{
  sprite.move(vel);
}

float player::getSpeed()
{
  return speed;
}

void player::setVelocity(sf::Vector2f vel)
{
  velocity = vel;
}

sf::Vector2f player::getVelocity()
{
  return velocity;
}

sf::FloatRect player::getGlobalBounds()
{
  return sf::FloatRect(sprite.getGlobalBounds());
}

sf::Vector2f player::getPosition()
{
  return sf::Vector2f(sprite.getPosition());
}

float player::getRadius()
{
  return radius;
}

void player::setPosition(float x, float y)
{
  sprite.setPosition(x,y);
}

sf::FloatRect player::getNextRect()
{
  float left = sprite.getPosition().x + getVelocity().x;
  float top = sprite.getPosition().y + getVelocity().y;
  float width = getGlobalBounds().width;
  float height = getGlobalBounds().height;

  return sf::FloatRect(left, top, width, height);
}
sf::Vector2f player::getCenter() const
{
  float x;
  float y;

  x = this->sprite.getPosition().x + (this->sprite.getGlobalBounds().width / 2) ;
  y = this->sprite.getPosition().y + (this->sprite.getGlobalBounds().height / 200);

  return sf::Vector2f (x,y);
}
