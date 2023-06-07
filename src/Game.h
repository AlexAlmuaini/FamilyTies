
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameObjects/player.h"
#include "GameObjects/playerMovement.h"
#include "GameObjects/Chain.h"
#include "GameObjects/Box.h"
#include "GameObjects/Key.h"
#include "GameObjects/GameObject.h"
#include "GameObjects/BoundingBox.h"
#include "GameObjects/PressurePlate.h"
#include "GameObjects/UIElement.h"
#include "GameObjects/Achievements.h"

#include "Menus/MenuSwitcher.h"
#include "Tilemap/Room1.h"
#include "Tilemap/Room2.h"
#include "Tilemap/Room3.h"
#include "Tilemap/Room4.h"
#include "tmxsrc/Tiles.h"
#include <tmxlite/Layer.hpp>
#include <tmxlite/Map.hpp>
#include <tmxlite/ObjectGroup.hpp>
#include <tmxlite/TileLayer.hpp>


class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();

  bool init();
  void update(float dt);
  void render(sf::Shader* shader = NULL);

  void roomSwitcher();

  void keyPressed(sf::Event event);
  void mouseClicked(sf::Event event);
  void joypadPressed(sf::Event event);
  void mouseMoved(sf::Event event);

  void TilemapInit();
  void ShaderInit();

  bool collisionCheck(sf::Sprite entity, sf::Sprite item, int id);
  void clamping(float dt);
  bool puzzle1();

  sf::VertexArray drawChain(sf::VertexArray chain,player player1, player player2);

  std::unique_ptr<MenuSwitcher>menuSwitcher;
  std::unique_ptr<PressurePlate>pp1;
  std::unique_ptr<PressurePlate>pp2;


 private:
  sf::RenderWindow& window;
  tmx::Map map;
  sf::Texture tileMap;
  sf::Text message;
  sf::Font font;
  sf::RectangleShape textBox;

  player player1;
  player player2;
  //std::unique_ptr<Chain> _chain;

  std::unique_ptr<Room1> pRoom1;
  std::unique_ptr<Room2> pRoom2;
  std::unique_ptr<Room3> pRoom3;
  std::unique_ptr<Room4> pRoom4;

  std::unique_ptr<Achievements> pAchievements;

  std::unique_ptr<Key> pHammer;
  std::unique_ptr<Key> pTorch;
  std::unique_ptr<Key> pKey;

  std::unique_ptr<Box> pHardendlock;

  sf::CircleShape player1Rad{120.0f};
  sf::CircleShape player2Rad{120.0f};
  sf::RectangleShape fade;


  player clamp;
  bool win = false;
  bool lockOpened = false;
  bool puzzleSolved = false;
  bool lose = false;
  bool renderAchievements = false;

  bool showTextBox = false;
  bool inRoom1 = true;
  bool inRoom2 = false;
  bool inRoom3 = false;
  bool inRoom4 = false;
  int room = 0;
  float fadeToBlack = 0;
  float fadeToBlackTimer = 0;
  float miniTimer = 0;
  bool nextRoom = false;
  bool hammerCollected;
  bool torchCollected;
  bool keyCollected;

  sf::Vector2f player1NextPosition, player2NextPosition;

  Box box;

  sf::Shader core_shader;

  UIElement UIPlayer1;
  UIElement UIPlayer2;
  UIElement UILight;
  UIElement UIBonkStick;
  UIElement UIKey;
  UIElement UIBanner;

  sf::View camera;

  ////Sounds
  sf::Music tunes;

  sf::SoundBuffer BonkSound;
  sf::Sound sound1;

  sf::SoundBuffer Lock;
  sf::Sound sound2;

  sf::SoundBuffer HardLock;
  sf::Sound sound3;

  void HammerInit();
  void TextBoxInit();
  void TorchInit();
  void KeyInit();
  static void GamepadInit();
  void FadeInit();
  void cameraManager();
};

#endif // PLATFORMER_GAME_H
