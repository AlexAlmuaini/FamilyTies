#ifndef SFMLGAME_GAMEOBJECT_H
#define SFMLGAME_GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject
{
 public:
  GameObject();
  virtual bool init() = 0;
  virtual void update(float dt) = 0;
  void initialiseSprite(std::string file_path);
  void setPosition(float x, float y);
  void setScale(float x, float y);
  void render(sf::RenderWindow& window, sf::Shader* shader= NULL);

 protected:
  sf::Sprite sprite;

 public:
  const sf::Sprite& getSprite() const;
  void setSprite(const sf::Sprite& sprite);

 protected:
  sf::Texture texture;
  bool visible;
};

#endif // SFMLGAME_GAMEOBJECT_H