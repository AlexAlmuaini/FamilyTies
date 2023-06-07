#include "Game.h"
#include <iostream>
#include <cmath>

Game::Game(sf::RenderWindow& game_window) : window(game_window)
{
  srand(time(NULL));
  menuSwitcher = std::make_unique<MenuSwitcher>(window);
}

Game::~Game() = default;

void Game::TilemapInit()
{
  pRoom1->Room1Init();
  pRoom2->Room2Init();
  pRoom3->Room3Init();
  pRoom4->Room4Init();
}
void Game::ShaderInit()
{
  if (!this->core_shader.loadFromFile("Data/Shaders/vertshader.vert", "Data/Shaders/fragshader.frag"))
  {
    std::cout << "Error: couldn't load shader" << std::endl;
  }
}
void Game::TextBoxInit()
{
  font.loadFromFile("Data/Fonts/Roboto/RobotoSlab-Bold.ttf");
  textBox.setSize(sf::Vector2f(16*5*10, 16*5*2));
  textBox.setPosition(window.getSize().x/2 - textBox.getSize().x/2,16*5*11);
  textBox.setFillColor(sf::Color(0,0,0));
  message.setFont(font);
  message.setCharacterSize(32);
  message.setFillColor(sf::Color::White);
  message.setPosition(textBox.getPosition().x + 32, textBox.getPosition().y + 32);
}
void Game::FadeInit()
{
  fade.setPosition(0,0);
  fade.setFillColor(sf::Color(0,0,0,0));
  fade.setSize(sf::Vector2f(1600,1200));
}
void Game::HammerInit()
{
  pHammer->texture.loadFromFile("Data/sprites/characters/BonkStick.png");
  pHammer->sprite.setTexture(pHammer->texture);
  pHammer->sprite.setScale(2.25,2.25);
  pHammer->sprite.setPosition(320,160);
  hammerCollected = false;
}
void Game::TorchInit()
{
  pTorch->texture.loadFromFile("Data/sprites/characters/Torch.png");
  pTorch->sprite.setTexture(pTorch->texture);
  pTorch->sprite.setScale(5,5);
  pTorch->sprite.setPosition(8.25*16*5,9*16*5);
  torchCollected = false;
}
void Game::KeyInit()
{
  pKey->texture.loadFromFile("Data/sprites/characters/key.png");
  pKey->sprite.setTexture(pKey->texture);
  pKey->sprite.setScale(5,5);
  pKey->sprite.setPosition(6.5*16*5,4*16*5);
  keyCollected = false;
}
void Game::GamepadInit()
{
  if (sf::Joystick::isConnected(0))
  {
    /// Gamepad controls
    std::cout << " Joystick 1 connected " << std::endl;
  }
  if (sf::Joystick::isConnected(1))
  {
    /// Gamepad controls
    std::cout << " Joystick 2 connected " << std::endl;
  }
}

bool Game::init()
{
  GamepadInit();

  ////init Level Stuff
  pRoom1 = std::make_unique<Room1>();
  pRoom2 = std::make_unique<Room2>();
  pRoom3 = std::make_unique<Room3>();
  pRoom4 = std::make_unique<Room4>();

  pAchievements = std::make_unique<Achievements>();

  pp1 = std::make_unique<PressurePlate>();
  pp2 = std::make_unique<PressurePlate>();

  pHammer = std::make_unique<Key>();
  pTorch = std::make_unique<Key>();
  pKey = std::make_unique<Key>();

  pHardendlock = std::make_unique<Box>();

  TextBoxInit();
  HammerInit();
  TorchInit();
  KeyInit();

  TilemapInit();
  ShaderInit();
  FadeInit();
  //_chain = std::make_unique<Chain>();

  pAchievements->AchievementsInit();

  ////Players Init
  {
    player1.init(1);
    player2.init(2);

    pp1->PPInit();
    pp2->PPInit();
    pp1->pp_sprite.setPosition(640, 100);
    pp2->pp_sprite.setPosition(900, 100);
    pHardendlock->init();
    pHardendlock->initialiseSprite("Data/Images/hardendPadlock.png");

    player1Rad.setPosition(
      window.getSize().x / 2 - 160, window.getSize().y / 2);
    player2Rad.setPosition(window.getSize().x / 2, window.getSize().y / 2);
  }

  ////UI Init
  {
    UIPlayer1.init(1);
    UIPlayer1.setPosition(100, 1050);
    UIPlayer1.setScale(6, 6);

    UIPlayer2.init(2);
    UIPlayer2.setPosition(1400, 1050);
    UIPlayer2.sprite.setOrigin(12.5, 0);
    UIPlayer2.setScale(-6, 6);

    UILight.init(3);
    UILight.setPosition(1225, 1040);
    UILight.setScale(9, 9.5);

    UIBonkStick.init(4);
    UIBonkStick.setPosition(200, 1030);
    UIBonkStick.setScale(4.5, 4.5);

    UIKey.init(5);
    UIKey.setPosition(720, 1040);
    UIKey.setScale(10, 10);

    UIBanner.init(6);
    UIBanner.setPosition(-25, 990);
    UIBanner.setScale(2.1, 0.75);
  }

  ////Camera Init
  {
    sf::View temp_view(sf::FloatRect(0, 0, 1600, 1200));
    camera = temp_view;
    window.setView(camera);
  }

  ////Sound Init
  {
    if (!tunes.openFromFile("Data/Sounds/Mystified-Spooky-Theme.ogg"))
    {
      std::cout << "Game Audio didn't load in :( \n";
    }

    tunes.setLoop(true);
    tunes.setVolume(100);
    tunes.play();


    if (!BonkSound.loadFromFile("Data/Sounds/bONKsOUND.wav"))
    {
      std::cout << "Game Audio didn't load in :( \n";
    }
    sound1.setBuffer(BonkSound);
    sound1.setLoop(false);

    if (!Lock.loadFromFile("Data/Sounds/LockSound.wav"))
    {
      std::cout << "Game Audio didn't load in :( \n";
    }
    sound2.setBuffer(Lock);
    sound2.setLoop(false);

    if (!HardLock.loadFromFile("Data/Sounds/HardenedPadlockOpened.wav"))
    {
      std::cout << "Game Audio didn't load in :( \n";
    }
    sound3.setBuffer(Lock);
    sound3.setLoop(false);
  }

  if (!tunes.openFromFile(
        "Data/Sounds/Mystified-Spooky-Theme.ogg"))
  {
    std::cout <<  "Game Audio didn't load in :( \n";
  }

  tunes.setLoop(true);
  tunes.setVolume(100);
  tunes.play();



  if (menuSwitcher->current_state == menuSwitcher->mainMenuState ||
      menuSwitcher->current_state == menuSwitcher->gameOverState)
  {
      menuSwitcher->init();
  }

  return true;
}

void Game::update(float dt)
{
  cameraManager();
  if (nextRoom)
  {
    roomSwitcher();
    pAchievements->AchievementsText(3);
    renderAchievements = false;
    nextRoom = false;
  }

  if (menuSwitcher->current_state == menuSwitcher->mainMenuState ||
      menuSwitcher->current_state == menuSwitcher->gameOverState) {
    if(sf::Joystick::isButtonPressed(0,1))
    {
      menuSwitcher->current_state = menuSwitcher->gamePlayState;
    }
      menuSwitcher->update(dt); }

  else if (menuSwitcher->current_state == menuSwitcher->gamePlayState) {

    ////update player
    player1.update(dt);
    player2.update(dt);

    ////update ui
    UIPlayer1.update(dt);
    UIPlayer2.update(dt);

    //// Player movement with Clamping & collision checks
    clamping(dt);

    //// Player - DoorCollision Checks
    if (inRoom1) {
      if (puzzle1()) { pRoom1->OpenDoor();
      pAchievements->AchievementsText(0);
      renderAchievements = true;}

      for (auto &j: pRoom1->Doortile) {
        for (auto &i: j) {
          collisionCheck(player1.sprite, i.tileSprite, i.tileID);
          collisionCheck(player2.sprite, i.tileSprite, i.tileID); }}}

    if (inRoom2) {
      if(collisionCheck(player1.sprite, pHammer->sprite, 1) && !hammerCollected)
      {
        hammerCollected = true;
        sound1.play();
      }


      if(collisionCheck(player2.sprite, pHammer->sprite, 1) && !hammerCollected)
      {
        message.setString("That's to heavy for you\nMaybe your brother can lift it...");
        showTextBox = true;
      }

      else
      {
        showTextBox = false;
      }

      if(collisionCheck(player2.sprite, box.getSprite(), 1) || collisionCheck(player1.sprite, box.getSprite(), 1))
      {
        if (!hammerCollected)
        {
          message.setString("This Lock Looks Weak\nMaybe We Could Find Something To Break It?");
          showTextBox = true;
        }
      }

      for (auto &j: pRoom2->Doortile) {
        for (auto &i: j) {
          collisionCheck(player1.sprite, i.tileSprite, i.tileID);
          collisionCheck(player2.sprite, i.tileSprite, i.tileID);
        }
      }
    }

    if (inRoom3) {
      //// Player Torch Pickup
      if(collisionCheck(player2.sprite, pTorch->sprite, 1) && !torchCollected)
      {
        torchCollected = true;
        sound1.play();
      }

      ////Text box code
      if(collisionCheck(player1.sprite, pTorch->sprite, 1) && !torchCollected)
      {
        message.setString("Your hands are already full\nMaybe your brother can carry it...");
        showTextBox = true;
      }

      else if (collisionCheck(player1.sprite, pHardendlock->getSprite(), 1) || collisionCheck(player2.sprite, pHardendlock->getSprite(), 1) )
      {
        if(!keyCollected)
        {
          message.setString("This lock is too strong to break\nLets find the key!");
          showTextBox = true;
        }
      }

      else
      {
        showTextBox = false;
      }

      ////Puzzle Logic
      if(keyCollected) {
        if (collisionCheck(player1.sprite, pHardendlock->getSprite(), 1) && !puzzleSolved || collisionCheck(player2.sprite, pHardendlock->getSprite(), 1) && !puzzleSolved)
        {
          pAchievements->AchievementsText(2);
          renderAchievements = true;
          pRoom3->OpenDoor();
          puzzleSolved = true;
          sound3.play();
        }
      }
      else
      {
        puzzleSolved = false;
      }

      ////Room 3 door collision check
      for (auto &j: pRoom3->Doortile) {
        for (auto &i: j) {
          collisionCheck(player1.sprite, i.tileSprite, i.tileID);
          collisionCheck(player2.sprite, i.tileSprite, i.tileID);
        }
      }

      if (collisionCheck(player1.sprite, pKey->getSprite(), 1) && !keyCollected  ||  collisionCheck(player2.sprite, pKey->getSprite(), 1) && !keyCollected)
      {
        keyCollected = true;
        sound1.play();
      }
    }

    //// End game cutscene Logic
    if(inRoom4)
    {
      player2.textureRectangle.top = player2.texture.getSize().y / 3 * 2;
      player1.textureRectangle.top = player1.texture.getSize().y / 3 * 2;

      player1Rad.move(0,-1);
      player2Rad.move(0,-1);

      fadeToBlackTimer += dt;
      miniTimer += dt;

      if(fadeToBlackTimer > 2)
      {
          fadeToBlack++;
          fade.setFillColor(sf::Color(0,0,0,fadeToBlack));
          miniTimer = 0;
      }
      if(fadeToBlackTimer > 6)
      {
        menuSwitcher->current_state = menuSwitcher->mainMenuState;
      }
    }
  }
}

void Game::render(sf::Shader* shader)
{

  //// Renders the menu in menu state
  if (menuSwitcher->current_state == menuSwitcher->mainMenuState ||
      menuSwitcher->current_state == menuSwitcher->gameOverState) {
      menuSwitcher->render(); }
  //// Renders the levels depending on which room is active
  else if (menuSwitcher->current_state == menuSwitcher->gamePlayState)
  {
      sf::VertexArray chain(sf::Quads, 4);

    //// Room Renderings
    if (inRoom1) {
      for (auto &j: pRoom1->Floortile) {
        for (auto &i: j) {
          window.draw(i.tileSprite); }}

      for (auto &j: pRoom1->Walltile) {
        for (auto &i: j) {
          window.draw(i.tileSprite); }}

      for (auto &j: pRoom1->Decortile) {
        for (auto &i: j) {
          window.draw(i.tileSprite); }}

      if(puzzleSolved) {
        for (auto &j: pRoom1->Doortile) {
          for (auto &i: j) {
            window.draw(i.tileSprite); }}}

      window.draw(pp1->pp_sprite);
      window.draw(pp2->pp_sprite);
    }

    if (inRoom2) {
      for (auto& j : pRoom2->Floortile) {
        for (auto& i : j) {
          window.draw(i.tileSprite); }}

      for (auto& j : pRoom2->Walltile) {
        for (auto& i : j) {
          window.draw(i.tileSprite); }}

      for (auto& j : pRoom2->Decortile) {
        for (auto& i : j) {
          window.draw(i.tileSprite); }}

      box.render(window);
      if(!hammerCollected)
      {
        window.draw(pHammer->sprite);
      }

      if (box.boxHealth <= 0) {
        puzzleSolved = true;
        for (auto& j : pRoom2->Doortile) {
          for (auto& i : j) {
            window.draw(i.tileSprite); }}}
      else
      {
        puzzleSolved = false;
      }
    }

    if (inRoom3) {
      ////static asset rendering logic
      for (auto &j: pRoom3->Floortile) {
        for (auto &i: j) {
          window.draw(i.tileSprite, &this->core_shader); }}

      for (auto &j: pRoom3->Walltile) {
        for (auto &i: j) {
          window.draw(i.tileSprite, &this->core_shader); }}

      for (auto &j: pRoom3->Decortile) {
        for (auto &i: j) {
          window.draw(i.tileSprite, &this->core_shader); }}

      ////variable asset rendering logic
      if(!torchCollected)
      {
        window.draw(pTorch->sprite);
      }

      //// shader stuff
      if (!keyCollected)
      {
        window.draw(pKey->sprite, &this->core_shader);
      }

      if(puzzleSolved)
      {
        for (auto& j : pRoom3->Doortile) {
          for (auto& i : j) {
            window.draw(i.tileSprite, &this->core_shader);
          }
        }
      }

      else
      {
        window.draw(pHardendlock->getSprite(), &this->core_shader);
      }

      player1.render(window, &this->core_shader);

      window.draw(drawChain(chain, player1, player2), &this->core_shader);

      if(!torchCollected)
      {
        player2.render(window, &this->core_shader);
      }

      else
      {
        player2.render(window);
      }
    }

    if (inRoom4) {
      for (auto &j: pRoom4->Floortile) {
        for (auto &i: j) {
          window.draw(i.tileSprite); }}

      for (auto &j: pRoom4->Walltile) {
        for (auto &i: j) {
          window.draw(i.tileSprite); }}

      for (auto &j: pRoom4->Decortile) {
        for (auto &i: j) {
          window.draw(i.tileSprite); }}
    }

    //// Room 2 lock render
    window.draw(box.crack);

    //// non shader rendering
    if(!inRoom3) {
      player1.render(window);
      player2.render(window);
      window.draw(drawChain(chain, player1, player2)); }

    if(torchCollected){
      core_shader.setUniform("hasTexture", true);
      core_shader.setUniform("lightPos", player2.getCenter());
    }

    else
    {
      core_shader.setUniform("hasTexture", true);
      core_shader.setUniform("lightPos", pTorch->sprite.getPosition());
    }

    //// static ui asset render logic
    UIBanner.render(window);

    UIPlayer1.render(window);
    UIPlayer2.render(window);

    //// variable ui asset render logic
    if(torchCollected)
    {
      UILight.render(window);
    }
    if(hammerCollected)
    {
      UIBonkStick.render(window);
    }
    if(keyCollected)
    {
      UIKey.render(window);
    }

    //// Text Box Rendering
    if(showTextBox)
    {
      window.draw(textBox);
      window.draw(message);
    }

    //// Fade to Black Cutscene Rendering
    window.draw(fade);

    if(renderAchievements)
    {
      window.draw(pAchievements->textBox);
      window.draw(pAchievements->message);
    }
  }
}

////Box Click Puzzle mainly
void Game::mouseClicked(sf::Event event)
{
  //// Changes Menu states when option is clicked
  if (menuSwitcher->current_state == menuSwitcher->mainMenuState ||
      menuSwitcher->current_state == menuSwitcher->gameOverState) {
      menuSwitcher->mouseClicked(event); }

  else if (menuSwitcher->current_state == menuSwitcher->gamePlayState) {
    ////get the click position


    if (collisionCheck(player1.sprite, box.getSprite(), 1) && hammerCollected) {
      box.hit(1);
      sound1.play();
      box.boxHealth--;

      if(box.boxHealth <= 0) {
        sound2.play();
        pAchievements->AchievementsText(1);
        renderAchievements = true;
        pRoom2->OpenDoor();
      }
    }
  }
}

//// DW - this is just fot the menu mouse movement
void Game::mouseMoved(sf::Event event)
{
  ////Menu Option Highlight code when mouse is hovering over
  if (menuSwitcher->current_state == menuSwitcher->mainMenuState ||
      menuSwitcher->current_state == menuSwitcher->gameOverState) {
      menuSwitcher->mouseMoved(event); }
}

//// Collision check currently used for Door player collision & Player Box Collision
bool Game::collisionCheck(sf::Sprite entity, sf::Sprite item, int id)
{
  BoundingBox entity_box = BoundingBox(entity);
  BoundingBox item_box = BoundingBox(item);

  if (entity_box.north_west.x < item_box.south_east.x &&
      entity_box.south_east.x > item_box.north_west.x &&
      entity_box.north_west.y < item_box.south_east.y &&
      entity_box.south_east.y > item_box.north_west.y && id != 0) {

    if (id == 23 || id == 24) {
      nextRoom = true;
      player1Rad.setPosition(680,816);
      player2Rad.setPosition(player1Rad.getPosition().x + 56, 816);
      return false;
    }
    return true;
  }
  return false;
}

//// Player Movement Clamping Code
void Game::clamping(float dt)
{
  player1.setPosition(player1Rad.getPosition().x + (player1Rad.getRadius()/2),player1Rad.getPosition().y + (player1Rad.getRadius()/2));
  player2.setPosition(player2Rad.getPosition().x + (player2Rad.getRadius()/2),player2Rad.getPosition().y + (player2Rad.getRadius()/2));

  ///Player1 Movement ~ For your own sanity, DO NOT OPEN!!
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y) <= -50) {

    ////Sprite animation direction setting
    player1.textureRectangle.top = player1.texture.getSize().y / 3 * 2;

    player1NextPosition = sf::Vector2f (player1.getPosition().x/5, player1.getPosition().y/5 - 1);
    player2NextPosition = sf::Vector2f (player2.getPosition().x/5, player2.getPosition().y/5-1);
    int i = int(player1NextPosition.x / 16);
    int j = int(player1NextPosition.y / 16);

    if(!clamp.clamped) {
      if (pRoom1->Walltile[j][i].tileID == 0) {

        if(inRoom1){if (pRoom1->Walltile[j][i].tileID == 0) {
            player1Rad.move(0,-6); }}

        if(inRoom2){if (pRoom2->Walltile[j][i].tileID == 0) {
            player1Rad.move(0,-6); }}

        if(inRoom3){if (pRoom3->Walltile[j][i].tileID == 0) {
            player1Rad.move(0,-6); }}
      }
    }

    if(puzzleSolved) {
      if(inRoom1){if (pRoom1->Walltile[j][i].tileID == 47 || pRoom1->Walltile[j][i].tileID == 48) {
          player1Rad.move(0,-6); }}

      if(inRoom2){if (pRoom2->Walltile[j][i].tileID == 47 || pRoom1->Walltile[j][i].tileID == 48) {
          player1Rad.move(0,-6); }}

      if(inRoom3){if (pRoom3->Walltile[j][i].tileID == 47 || pRoom1->Walltile[j][i].tileID == 48) {
          player1Rad.move(0,-6); }}
    }
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y) >= 50) {

    ////Sprite animation direction setting
    player1.textureRectangle.top = player1.texture.getSize().y / 3 * 0;

    player1NextPosition = sf::Vector2f (player1.getPosition().x/5, (player1.getPosition().y + player1.sprite.getGlobalBounds().height)/5 + 1);
    int i = int(player1NextPosition.x / 16);
    int j = int(player1NextPosition.y / 16);

    if(inRoom1){if (pRoom1->Walltile[j][i].tileID == 0) {
        player1Rad.move(0,6); }}

    if(inRoom2){if (pRoom2->Walltile[j][i].tileID == 0) {
        player1Rad.move(0,6); }}

    if(inRoom3){if (pRoom3->Walltile[j][i].tileID == 0) {
        player1Rad.move(0,6); }}
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) >= 50) {

    ////Sprite animation direction setting
    player1.textureRectangle.top = player1.texture.getSize().y / 3 * 1;
    player1.sprite.setScale(player1.scale, player1.scale);

    player1NextPosition = sf::Vector2f ((player1.getPosition().x + player1.sprite.getGlobalBounds().width)/5 -5, player1.getPosition().y/5  + player1.getGlobalBounds().height/5);
    int i = int(player1NextPosition.x / 16);
    int j = int(player1NextPosition.y / 16);

    if(inRoom1){if (pRoom1->Walltile[j][i].tileID == 0) {
        player1Rad.move(6,0); }}

    if(inRoom2){if (pRoom2->Walltile[j][i].tileID == 0) {
        player1Rad.move(6,0); }}

    if(inRoom3){if (pRoom3->Walltile[j][i].tileID == 0) {
        player1Rad.move(6,0); }}
  }

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X)<= -50) {
    ////Sprite animation direction setting
    player1.textureRectangle.top = player1.texture.getSize().y / 3 * 1;
    player1.sprite.setScale(-player1.scale, player1.scale);

    player1NextPosition = sf::Vector2f (player1.getPosition().x/5 - 7, player1.getPosition().y/5  + player1.getGlobalBounds().height/5);
    int i = int(player1NextPosition.x / 16);
    int j = int(player1NextPosition.y / 16);

    if(inRoom1){if (pRoom1->Walltile[j][i].tileID == 0) {
        player1Rad.move(-6,0); }}

    if(inRoom2){if (pRoom2->Walltile[j][i].tileID == 0) {
        player1Rad.move(-6,0); }}

    if(inRoom3){if (pRoom3->Walltile[j][i].tileID == 0) {
        player1Rad.move(-6,0); }}
  }

  ///Player2 Movement ~ Please for the love of the Gods, DO NOT OPEN!!
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)|| sf::Joystick::getAxisPosition(1, sf::Joystick::Axis::Y) <= -50) {

    ////Sprite animation direction setting
    player2.textureRectangle.top = player2.texture.getSize().y / 3 * 2;

    player2NextPosition = sf::Vector2f (player2.getPosition().x/5, player2.getPosition().y/5 - 1);
    int i = int(player2NextPosition.x / 16);
    int j = int(player2NextPosition.y / 16);
    if (pRoom1->Walltile[j][i].tileID == 0)
    {
      if(inRoom1){if (pRoom1->Walltile[j][i].tileID == 0)
        {
          player2Rad.move(0,-6);
        }}
      if(inRoom2){if (pRoom2->Walltile[j][i].tileID == 0)
        {
          player2Rad.move(0,-6);
        }}
      if(inRoom3){if (pRoom3->Walltile[j][i].tileID == 0)
        {
          player2Rad.move(0,-6);
        }}
    }

    if(puzzleSolved)
    {

      if(inRoom1){if (pRoom1->Walltile[j][i].tileID == 47 || pRoom1->Walltile[j][i].tileID == 48)
        {
          player2Rad.move(0,-6);
        }}
      if(inRoom2){if (pRoom2->Walltile[j][i].tileID == 47 || pRoom1->Walltile[j][i].tileID == 48)
        {
          player2Rad.move(0,-6);
        }}
      if(inRoom3){if (pRoom3->Walltile[j][i].tileID == 47 || pRoom1->Walltile[j][i].tileID == 48)
        {
          player2Rad.move(0,-6);
        }}
    }
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)|| sf::Joystick::getAxisPosition(1, sf::Joystick::Axis::Y) >= 50)
  {
    ////Sprite animation direction setting
    player2.textureRectangle.top = player2.texture.getSize().y / 3 * 0;

    player2NextPosition = sf::Vector2f (player2.getPosition().x/5, (player2.getPosition().y + player2.sprite.getGlobalBounds().height)/5 + 1);
    int i = int(player2NextPosition.x / 16);
    int j = int(player2NextPosition.y / 16);

    if(inRoom1){if (pRoom1->Walltile[j][i].tileID == 0)
      {
        player2Rad.move(0,6);
      }}
    if(inRoom2){if (pRoom2->Walltile[j][i].tileID == 0)
      {
        player2Rad.move(0,6);
      }}
    if(inRoom3){if (pRoom3->Walltile[j][i].tileID == 0)
      {
        player2Rad.move(0,6);
      }}
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)|| sf::Joystick::getAxisPosition(1, sf::Joystick::Axis::X) >= 50)
  {
    ////Sprite animation direction setting
    player2.textureRectangle.top = player2.texture.getSize().y / 3 * 1;
    player2.sprite.setScale(player2.scale, player2.scale);

    player2NextPosition = sf::Vector2f ((player2.getPosition().x + player2.sprite.getGlobalBounds().width)/5 - 5, player2.getPosition().y/5 + player2.getGlobalBounds().height/5);
    int i = int(player2NextPosition.x / 16);
    int j = int(player2NextPosition.y / 16);
    if(inRoom1){if (pRoom1->Walltile[j][i].tileID == 0)
      {
        player2Rad.move(6,0);
      }}
    if(inRoom2){if (pRoom2->Walltile[j][i].tileID == 0)
      {
        player2Rad.move(6,0);
      }}
    if(inRoom3){if (pRoom3->Walltile[j][i].tileID == 0)
      {
        player2Rad.move(6,0);
      }}

  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)|| sf::Joystick::getAxisPosition(1, sf::Joystick::Axis::X) <= -50)
  {
    ////Sprite animation direction setting
    player2.textureRectangle.top = player2.texture.getSize().y / 3 * 1;
    player2.sprite.setScale(-player2.scale, player2.scale);

    player2NextPosition = sf::Vector2f (player2.getPosition().x/5 - 7, player2.getPosition().y/5 + player2.getGlobalBounds().height/5);
    int i = int(player2NextPosition.x / 16);
    int j = int(player2NextPosition.y / 16);

    if(inRoom1){if (pRoom1->Walltile[j][i].tileID == 0)
      {
        player2Rad.move(-6,0);
      }}
    if(inRoom2){if (pRoom2->Walltile[j][i].tileID == 0)
      {
        player2Rad.move(-6,0);
      }}
    if(inRoom3){if (pRoom3->Walltile[j][i].tileID == 0)
      {
        player2Rad.move(-6,0);
      }}
  }

  /// player movement normal if not clamped
  if(!clamp.clamped)
  {
    player1Rad.move(player1.getVelocity());
    player2Rad.move(player2.getVelocity());
  }

  /// if players are clamped, set new velocity based on player1 and player2 velocity
  if(clamp.clamped)
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
    clamp.clamped = false;
  }

  else
  {
    clamp.clamped = true;

    sf::Vector2f p1pos = player1Rad.getPosition();
    sf::Vector2f p2pos = player2Rad.getPosition();

    p1pos.x -= overlap * (p1x - p2x) / distance;
    p1pos.y -= overlap * (p1y - p2y) / distance;

    p2pos.x += overlap * (p1x - p2x) / distance;
    p2pos.y += overlap * (p1y - p2y) / distance;

    player1Rad.setPosition(p1pos);
    player2Rad.setPosition(p2pos);
    clamp.clamped = false;
  }
}

//// Line Draw Between Player Code
sf::VertexArray Game::drawChain(sf::VertexArray chain, player player1, player player2)
{
  chain[0].position= sf::Vector2f(player1.getPosition().x, player1.getPosition().y + player1.getGlobalBounds().height + 5);
  chain[1].position = sf::Vector2f(player1.getPosition().x + 5, player1.getPosition().y + player1.getGlobalBounds().height);
  chain[2].position = sf::Vector2f(player2.getPosition().x, player2.getPosition().y + player2.getGlobalBounds().height - 5);
  chain[3].position = sf::Vector2f(player2.getPosition().x + 5, player2.getPosition().y + player2.getGlobalBounds().height);

  return chain;
}

//// Pressure plate Puzzle
bool Game::puzzle1()
{
  if (collisionCheck(player1.sprite, pp1->pp_sprite,1) || collisionCheck(player2.sprite, pp1->pp_sprite,1)) {
    pp1->active = true;
  }

  else {
    pp1->active = false;
  }

  if (collisionCheck(player1.sprite, pp2->pp_sprite,1) || collisionCheck(player2.sprite, pp2->pp_sprite,1)) {
    pp2->active = true;
  }

  else {
    pp2->active = false;
  }

  if (pp1->active && pp2->active) {
    puzzleSolved = true;
    return true;
  }

  return false;
}

//// Room switching code
void Game::roomSwitcher()
{
  room += 1;

  switch (room)
  {
    case 0:
      inRoom1 = true;
      break;

    case 1:
      inRoom1 = false;
      inRoom2 = true;
      break;

    case 2:
      inRoom2 = false;
      inRoom3 = true;
      break;

    case 3:
      inRoom3 = false;
      inRoom4 = true;
      break;

    default:
      break;
  }
}

//// Room skip for devs

void Game::keyPressed(sf::Event event) {
  if(event.key.code == sf::Keyboard::Num1)
  {
    inRoom1 = true;
    inRoom2 = false;
    inRoom3 = false;
    inRoom4 = false;
  }
  if(event.key.code == sf::Keyboard::Num2)
  {
    inRoom1 = false;
    inRoom2 = true;
    inRoom3 = false;
    inRoom4 = false;
  }
  if(event.key.code == sf::Keyboard::Num3)
  {
    inRoom1 = false;
    inRoom2 = false;
    inRoom3 = true;
    inRoom4 = false;
  }
  if(event.key.code == sf::Keyboard::Num4)
  {
    inRoom1 = false;
    inRoom2 = false;
    inRoom3 = false;
    inRoom4 = true;
  }
}

void Game::cameraManager()
  {
  ////Camera Code
  sf::View temp_view(sf::FloatRect(0, 0, 1600, 1200));
  camera   = temp_view;

  int screen_width  = 1600;
  int screen_height = 1200;
  int camera_width  = 1600;
  int camera_height = 1200;

  sf::Vector2f players_midpoint;
  players_midpoint.x = (player1.getPosition().x + player2.getPosition().x )/2;
  players_midpoint.y = (player1.getPosition().y + player2.getPosition().y )/2;
  camera.setCenter(camera_width / 2, camera_height / 2);
  ////Camera code for if we zoomed in, this would lock the bounds of the camera however
  //// we chose not to use this style of camera
  /*if ( players_midpoint.y - camera_height / 2 < 0) {
    if (players_midpoint.x - camera_width / 2 < 0) {
      // Top left
      camera.setCenter(camera_width / 2, camera_height / 2); }

    else if (players_midpoint.x + camera_width / 2 > screen_width)  {
      // Top right
      camera.setCenter(screen_width - camera_width / 2, camera_height / 2);}

    else {
      // Top mid
      camera.setCenter(players_midpoint.x, camera_height / 2); }}
  else if ( players_midpoint.y + camera_height / 2 > screen_height)
  {
    if (players_midpoint.x - camera_width / 2 < 0)
    {
      // Bottom left
      camera.setCenter(camera_width / 2, screen_height - camera_height / 2);
    }

    else if (players_midpoint.x + camera_width / 2 > screen_width)
    {
      // bottom right
      camera.setCenter(screen_width - camera_width / 2,screen_height - camera_height / 2);
    }

    else
    {
      // bottom mid
      camera.setCenter(players_midpoint.x,screen_height - camera_height / 2);
    }
  }
  else
  {
    if (players_midpoint.x - camera_width / 2 < 0)
    {
      // Middle left
      camera.setCenter(camera_width / 2, players_midpoint.x);
    }

    else if (players_midpoint.x + camera_width / 2 > screen_width)
    {
      // Middle right
      camera.setCenter(screen_width - camera_width / 2,players_midpoint.x);
    }

    else
    {
      // Middle mid
      camera.setCenter(players_midpoint.x, players_midpoint.y);
    }
  }*/

  window.setView(camera);
}

  void Game::joypadPressed(sf::Event event)
  {
    if (event.key.code == sf::Joystick::isButtonPressed(0,0))
    {
      ////get the click position
      if (collisionCheck(player1.sprite, box.getSprite(), 1) && hammerCollected)
      {
        box.hit(1);
        sound1.play();
        box.boxHealth--;

        if (box.boxHealth <= 0)
        {
          pAchievements->AchievementsText(1);
          renderAchievements = true;
          sound2.play();
          pRoom2->OpenDoor();
        }
      }
    }
  }
