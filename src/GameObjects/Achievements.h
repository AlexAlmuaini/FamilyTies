//
// Created by AlexA on 4/24/2023.
//

#ifndef SFMLGAME_ACHIEVEMENTS_H
#define SFMLGAME_ACHIEVEMENTS_H
#include <SFML/Graphics.hpp>


class Achievements
{
 public:
  Achievements();
  void AchievementsInit();
  void AchievementsText(int achievement);
  sf::Text message;
  sf::Font font;
  sf::RectangleShape textBox;
 private:
};

#endif // SFMLGAME_ACHIEVEMENTS_H
