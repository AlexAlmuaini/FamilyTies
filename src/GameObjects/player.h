#ifndef SFMLGAME_PLAYER_H
#define SFMLGAME_PLAYER_H

#include <SFML/Graphics.hpp>

class player
{
 public:
  player();
  void init(int input);
  void update(float dt);
  void render(sf::RenderWindow& window, sf::Shader* shader = NULL);


  void move(sf::Vector2f vel);

  float getSpeed();
  sf::Vector2f getVelocity();
  sf::FloatRect getGlobalBounds();
  sf::Vector2f getPosition();
  sf::Vector2f getCenter() const;
  void setPosition(float x, float y);
  float getRadius();
  sf::FloatRect getNextRect();

  void setVelocity(sf::Vector2f);

  bool clamped;

  sf::Clock animationClock;


  int ID;

  sf::Sprite sprite;
  sf::Texture texture;
  sf::IntRect textureRectangle;

  float scale = 3.5;

  int xVel, yVel;

 private:

  sf::Vector2f velocity {0,0};

  float radius = 10;

  float speed = 400;

  std::string inventory[8];


};

#endif // SFMLGAME_PLAYER_H
