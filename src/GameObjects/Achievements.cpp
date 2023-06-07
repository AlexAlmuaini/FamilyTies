//
// Created by AlexA on 4/24/2023.
//

#include "Achievements.h"
Achievements::Achievements() {}

void Achievements::AchievementsInit()
{
  font.loadFromFile("Data/Fonts/Roboto/RobotoSlab-Bold.ttf");
  textBox.setSize(sf::Vector2f(16*5*3, 16*5*1));
  textBox.setPosition(1600 - textBox.getSize().x -16 ,16);
  textBox.setFillColor(sf::Color::Black);
  message.setFont(font);
  message.setCharacterSize(32);
  message.setFillColor(sf::Color::White);
  message.setPosition(textBox.getPosition().x + 16, textBox.getPosition().y + 16);
}
void Achievements::AchievementsText(int achievement)
{
  if (achievement == 0)
  {
    message.setString("Teamwork");
  }
  if (achievement == 1)
  {
    message.setString("Hammer Time");
  }
  if (achievement == 2)
  {
    message.setString("Freedom");
  }
  if (achievement == 3)
  {
    message.setString("");
  }
}
