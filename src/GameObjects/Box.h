#ifndef SFMLGAME_BOX_H
#define SFMLGAME_BOX_H

#include "GameObject.h"

class Box : public GameObject
{
 public:
  Box();
  bool init() override;
  void update(float dt) override;
  void update_overlay();
  void hit (int dmg);
  bool despawn();
  sf::Sprite crack;
  int boxHealth = 10;
 private:
  int damage;
  sf::Texture crack_texture;
  bool has_key;

};

#endif // SFMLGAME_BOX_H
