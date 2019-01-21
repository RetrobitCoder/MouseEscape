#ifndef maus_h
#define maus_h

#include <Arduboy2.h>

class Maus
{
  public:
    Maus(){};
    byte getX();
    byte getY();
    byte getSpeed();
    void updateMaus(byte newX, byte newY);
  private:
    byte x;
    byte y;
    byte moveSpeed = 4;
};

#endif

