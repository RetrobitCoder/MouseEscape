#include <Arduboy2.h>
#include <Sprites.h>
#include "Bitmaps.h"
#include "Constants.h"
#include "Maus.h"
#include "Food.h"
#include "Snake.h"
#include "Level.h"

enum class GameState : unsigned char
{
  Title, Play, Pause, Win, GameOver
};

Arduboy2 ab;
Sprites sprites;
GameState gameState = GameState::Title;
const byte FPS = 60;

Maus maus;
Snake snake;
byte frame = 6;
Level level;

void setup()
{
  ab.begin();
  ab.clear();
  ab.initRandomSeed();
}

void titleScreen()
{
  ab.setCursor(WIDTH / 2 - 32, HEIGHT / 2);
  ab.print("Mouse Escape");
  ab.setCursor(24, HEIGHT - 8);
  ab.print("Press A Button");

  if (ab.pressed(A_BUTTON))
  {
    gameState = GameState::Play;
    ab.delayShort(200);
    level.start(&maus);
  }
}

void draw()
{
  sprites.drawSelfMasked(maus.getX(), maus.getY(), mouseSprite, frame);
  level.levelDraw(&sprites);
  //sprites.drawSelfMasked(32,0, snakeSprite, 0);
  //sprites.drawSelfMasked(32, 1*snakeSprite[1], snakeSprite, 1);
  //sprites.drawSelfMasked(32, 2*snakeSprite[1], snakeSprite, 1);
  //sprites.drawSelfMasked(32, 3*snakeSprite[1], snakeSprite, 2);
}

void boundaryCheck()
{
  byte x = maus.getX();
  byte y = maus.getY();

  if(y + mouseSprite[1] > HEIGHT && y < 200) y = HEIGHT - mouseSprite[1];
  else if(y > 200 || y < 11) y = 11;
 

  if(x + mouseSprite[0] > WIDTH && x < 200) x = WIDTH - mouseSprite[0];
  else if(x > 200) x = 0;

  maus.updateMaus(x, y);
}

void updateGame()
{
  if (ab.pressed(LEFT_BUTTON))
  {
    if (frame == 2) frame = 3;
    else frame = 2;

    maus.updateMaus(maus.getX() - maus.getSpeed(), maus.getY());
  }
  else if (ab.pressed(RIGHT_BUTTON))
  {
    if (frame == 4) frame = 5;
    else frame = 4;

    maus.updateMaus(maus.getX() + maus.getSpeed(), maus.getY());
  }
  else if (ab.pressed(UP_BUTTON))
  {
    if (frame == 6) frame = 7;
    else frame = 6;

    maus.updateMaus(maus.getX(), maus.getY() - maus.getSpeed());
  }
  else if (ab.pressed(DOWN_BUTTON))
  {
    if (frame == 0) frame = 1;
    else frame = 0;

    maus.updateMaus(maus.getX(), maus.getY() + maus.getSpeed());
  }

  boundaryCheck();
  level.collisionCheck(&maus);
  
  if (level.levelState() == LevelState::Won) gameState = GameState::Win;
  else if(level.levelState() == LevelState::Lost) gameState = GameState::GameOver;
  //TODO: draw snakes
  //TODO: move snakes
  //TODO: add pause to game
}

void gameLoop()
{
  ab.clear();
  draw();
  ab.delayShort(100);
}

void gameWon()
{
  ab.clear();
  ab.setCursor(WIDTH/2, HEIGHT/2);
  ab.print("You Win");
}

void gameLost()
{
  ab.clear();
  ab.setCursor(WIDTH/2, HEIGHT/2);
  ab.print("You Lost");
}

void loop()
{
  if (!ab.nextFrame()) return;

  ab.pollButtons();

  switch (gameState)
  {
    case GameState::Title:
      titleScreen();
      break;
    case GameState::Play:
      gameLoop();
      updateGame();
      break;
    case GameState::Pause:
      break;
    case GameState::Win:
      gameWon();
      break;
    case GameState::GameOver:
      gameLost();
      break;
  }

  ab.display();
}
