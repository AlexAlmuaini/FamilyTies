//
// Created by Steven on 18/04/2023.
//

#include "UIElement.h"

UIElement::UIElement() {}

void UIElement::init(int input){
  if (input == 1){
    texture.loadFromFile("Data/sprites/characters/PLAYER1.png");  }

  else if (input == 2){
    texture.loadFromFile("Data/sprites/characters/PLAYER2.png");  }

  textureRectangle = sf::IntRect(0, texture.getSize().y / 3 * 1, texture.getSize().x / 6, texture.getSize().y / 3);
  sprite.setTextureRect(textureRectangle);

  if (input == 3){
    texture.loadFromFile("Data/sprites/characters/Torch.png"); }

  else if (input == 4){
    texture.loadFromFile("Data/sprites/characters/BonkStick.png"); }

  else if (input == 5){
    texture.loadFromFile("Data/sprites/characters/key.png"); }

  else if (input == 6){
    texture.loadFromFile("Data/sprites/ParchmentBorder.png"); }

  sprite.setTexture(texture);
}

void UIElement::update(float dt){
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

void UIElement::render(sf::RenderWindow& window){
  window.draw(sprite);
}

void UIElement::setPosition(float x, float y){
  sprite.setPosition(x,y);
}

void UIElement::setScale(float x, float y){
  sprite.setScale(x,y);
}

//// Legacy ideas
//void UIElement::update(float dt) {}

//void UIElement::setIsVisible(bool value)
//{
//  is_visible = value;
//}
//
//bool UIElement::getIsVisible()
//{
//  return is_visible;


