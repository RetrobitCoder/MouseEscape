#include "Maus.h"

/*** Public ***/

byte Maus::getX()
{
  return this->x;
}

byte Maus::getY()
{
  return this->y;
}

byte Maus::getSpeed()
{
  return this->moveSpeed;
}

void Maus::updateMaus(byte newX, byte newY)
{
  this->x = newX;
  this->y = newY;
}
/*** Private ***/
