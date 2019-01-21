#include "Snake.h"

/*** Public ***/

Snake::Snake(byte startX, byte startY, char initDir, byte bodyLength)
{
  this->x = startX;
  this->y = startY;
  this->facing = initDir;
  this->len = bodyLength;
}

byte Snake::getX()
{
  return this->x;
}

byte Snake::getY()
{
  return this->y;
}

byte Snake::getSpeed()
{
  return this->moveSpeed;
}

void Snake::updateSnake(byte newX, byte newY)
{
  this->x = newX;
  this->y = newY;
}

void Snake::drawSnake(Sprites* sprite)
{
  sprite->drawSelfMasked(32,0, snakeSprite, 0);
}

/*** Private ***/
