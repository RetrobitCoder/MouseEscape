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

char Snake::getFacing()
{
  return this->facing;
}

void Snake::updateSnake(byte newX, byte newY)
{
  //updateBody(Body, this->x, this->y);
  this->x = newX;
  this->y = newY;
}

void Snake::drawSnake(Sprites* sprite)
{
  byte frame = 0;
  switch(this->facing)
  {
    case 'u':
      frame = 0;
      break;
    case 'd':
      frame = 5;
      break;
    case 'r':
      frame = 6;
      break;
    case 'l':
      frame = 9;
      break;
  }
  sprite->drawSelfMasked(this->x,this->y, snakeSprite, frame);
}

/*** Private ***/
void Snake::updateBody(body* part, byte newX, byte newY)
{
  if(part != NULL)
  {
    updateBody(part->next, part->x, part->y);
    part->x = newX;
    part->y = newY;
  }
}
