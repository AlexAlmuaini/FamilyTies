#include "GameObject.h"
GameObject::GameObject()
{
}

void GameObject::initialiseSprite(std::string file_path)
{
  texture.loadFromFile(file_path);
  sprite.setTexture(texture);
}

void GameObject::setPosition(float x, float y)
{
  sprite.setPosition(x,y);
}

void GameObject::render(sf::RenderWindow& window, sf::Shader* shader)
{
  if (visible)
  {
    window.draw(sprite);
  }
}
void GameObject::setScale(float x, float y)
{
  sprite.setScale(x,y);
}
const sf::Sprite& GameObject::getSprite() const
{
  return sprite;
}
void GameObject::setSprite(const sf::Sprite& sprite)
{
  GameObject::sprite = sprite;
}
