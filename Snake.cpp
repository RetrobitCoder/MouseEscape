#include "Snake.h"

/*** Public ***/

Snake::Snake(byte startX, byte startY, char initDir, byte bodyLength)
{
  this->x = startX;
  this->y = startY;
  this->facing;
  
  body* current = new body;
  current->x = getBodyPos1(initDir, startX, startY, 1);
  current->y = getBodyPos2(initDir, startX, startY);
  current->next = NULL;
  
  for(int i = 1; i <= bodyLength; i++)
  {
    body* part = new body;
    part->next = NULL;
    part->x = getBodyPos1(initDir, startX, startY, i + 1);
    part->y = getBodyPos2(initDir, startX, startY);
    current->next = part;
    current = part;
  }
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

byte Snake::getBodyPos1(char facing, byte x, byte y, byte bodyIndex)
{
  switch(facing)
  {
    case 'l':
      return (x - (bodyIndex * snakeSprite[0]));
    case 'r':
      return (x + (bodyIndex * snakeSprite[0]));
    case 'u':
      return (y + (bodyIndex * snakeSprite[1]));
    case 'd':
      return (y - (bodyIndex * snakeSprite[1]));
  }
}

byte Snake::getBodyPos2(char facing, byte x, byte y)
{
  switch(facing)
  {
    case 'l':
    case 'r':
      return y;
    case 'u':
    case 'd':
      return x;
  }
}
