#include "Snake.h"

/*** Public ***/

Snake::Snake(byte startX, byte startY, char initDir, byte bodyLength)
{
  this->x = startX;
  this->y = startY;
  this->facing = initDir;
  this->len = bodyLength;
  switch(this->facing)
  {
    case 'u':
      this->frame = 0;
      break;
    case 'd':
      this->frame = 5;
      break;
    case 'r':
      this->frame = 6;
      break;
    case 'l':
      this->frame = 9;
      break;
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
  this->x = newX;
  this->y = newY;
}

void Snake::drawSnake(Sprites* sprite)
{
  sprite->drawOverwrite(this->x,this->y, snakeSprite, this->frame);

  byte x;
  byte y;
  byte frame;
  
  for(int i = 1; i <= this->len; i++)
  {
    if(i == this->len)
    {
      frame = getFrame(this->facing, true);
      x = getBodyPos1(this->facing, this->x, this->y, this->len);
      y = getBodyPos2(this->facing, this->x, this->y, this->len);
    }
    else{
      frame = getFrame(this->facing, false);
      x = getBodyPos1(this->facing, this->x, this->y, this->len - i);
      y = getBodyPos2(this->facing, this->x, this->y, this->len - i);
    }
    sprite->drawOverwrite(x, y, snakeSprite, frame);
  }
}

/*** Private ***/
byte Snake::getBodyPos1(char facing, byte x, byte y, byte bodyIndex)
{
  switch(facing)
  {
    case 'l':
      return (x + (bodyIndex * snakeSprite[0]));
    case 'r':
      return (x - (bodyIndex * snakeSprite[0]));
    case 'u':
    case 'd':
      return x;
  }
}

byte Snake::getBodyPos2(char facing, byte x, byte y, byte bodyIndex)
{
  switch(facing)
  {
    case 'l':
    case 'r':
      return y;
    case 'u':
      return (y + (bodyIndex * snakeSprite[1]));
    case 'd':
      return (y - (bodyIndex * snakeSprite[1]));
  }
}

byte Snake::getFrame(char facing, bool isTail)
{
  switch(facing)
  {
    case 'l':
      if(isTail) return 11;
      else return 10;
    case 'r':
      if(isTail) return 8;
      else return 7;
    case 'u':
      if(isTail) return 2;
      else return 1;
    case 'd':
      if(isTail) return 3;
      else return 4;
  }
}
