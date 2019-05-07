#ifndef snake_h
#define snake_h

#include <Arduboy2.h>

const unsigned char PROGMEM snakeSprite[] =
{
// width, height,
16, 16,
// FRAME 00
0x80, 0xe0, 0xf0, 0xfc, 0xfe, 0xf9, 0xf9, 0xff, 0xff, 0xf9, 0xf9, 0xfe, 0xfc, 0xf0, 0xe0, 0x80, 
0x3f, 0x77, 0xec, 0xe8, 0xe8, 0xec, 0xf7, 0x7f, 0x7f, 0xf7, 0xec, 0xe8, 0xe8, 0xec, 0x77, 0x3f, 
// FRAME 01
0x00, 0xfc, 0xba, 0xbb, 0xd7, 0xd7, 0xbb, 0x7c, 0x7c, 0xbb, 0xd7, 0xd7, 0xbb, 0xba, 0xfc, 0x00, 
0x00, 0x3f, 0xdd, 0xdd, 0xeb, 0xeb, 0xdd, 0x3e, 0x3e, 0xdd, 0xeb, 0xeb, 0xdd, 0xdd, 0x3f, 0x00, 
// FRAME 02
0x00, 0x00, 0xb6, 0x6d, 0xdb, 0xb7, 0x6b, 0x5d, 0x5d, 0x6b, 0xb7, 0xdb, 0x6d, 0xb6, 0x00, 0x00, 
0x00, 0x00, 0x05, 0x0b, 0x16, 0x35, 0x55, 0xb5, 0xb5, 0x55, 0x35, 0x16, 0x0b, 0x05, 0x00, 0x00, 
// FRAME 03
0x00, 0x00, 0xa0, 0xd0, 0x68, 0xac, 0xaa, 0xad, 0xad, 0xaa, 0xac, 0x68, 0xd0, 0xa0, 0x00, 0x00, 
0x00, 0x00, 0x6d, 0xb6, 0xdb, 0xed, 0xd6, 0xba, 0xba, 0xd6, 0xed, 0xdb, 0xb6, 0x6d, 0x00, 0x00, 
// FRAME 04
0x00, 0xfc, 0xbb, 0xbb, 0xd7, 0xd7, 0xbb, 0x7c, 0x7c, 0xbb, 0xd7, 0xd7, 0xbb, 0xbb, 0xfc, 0x00, 
0x00, 0x3f, 0x5d, 0xdd, 0xeb, 0xeb, 0xdd, 0x3e, 0x3e, 0xdd, 0xeb, 0xeb, 0xdd, 0x5d, 0x3f, 0x00, 
// FRAME 05
0xfc, 0xee, 0x37, 0x17, 0x17, 0x37, 0xef, 0xfe, 0xfe, 0xef, 0x37, 0x17, 0x17, 0x37, 0xee, 0xfc, 
0x01, 0x07, 0x0f, 0x3f, 0x7f, 0x9f, 0x9f, 0xff, 0xff, 0x9f, 0x9f, 0x7f, 0x3f, 0x0f, 0x07, 0x01, 
// FRAME 06
0x7c, 0xfe, 0xff, 0xc3, 0xbd, 0xe7, 0xc3, 0xc3, 0xff, 0xfe, 0xfe, 0xfc, 0xf8, 0x98, 0x90, 0xe0, 
0x3e, 0x7f, 0xff, 0xc3, 0xbd, 0xe7, 0xc3, 0xc3, 0xff, 0x7f, 0x7f, 0x3f, 0x1f, 0x19, 0x09, 0x07, 
// FRAME 07
0x7c, 0x7c, 0xb2, 0xce, 0xfe, 0xce, 0xb2, 0x7e, 0x7e, 0xb2, 0xce, 0xfe, 0xce, 0xb2, 0x7c, 0x78, 
0x3e, 0x3e, 0x4d, 0x73, 0x7f, 0x73, 0x4d, 0x7e, 0x7e, 0x4d, 0x73, 0x7f, 0x73, 0x4d, 0x3e, 0x1e, 
// FRAME 08
0x80, 0x40, 0xa0, 0xf0, 0x08, 0xf4, 0x18, 0xec, 0x34, 0xd8, 0x6c, 0xb4, 0xd8, 0xac, 0x74, 0xf8, 
0x01, 0x02, 0x05, 0x0f, 0x10, 0x2f, 0x18, 0x37, 0x2c, 0x1b, 0x36, 0x2d, 0x1b, 0x35, 0x2e, 0x1f, 
// FRAME 09
0xe0, 0x90, 0x98, 0xf8, 0xfc, 0xfe, 0xfe, 0xff, 0xc3, 0xc3, 0xe7, 0xbd, 0xc3, 0xff, 0xfe, 0x7c, 
0x07, 0x09, 0x19, 0x1f, 0x3f, 0x7f, 0x7f, 0xff, 0xc3, 0xc3, 0xe7, 0xbd, 0xc3, 0xff, 0x7f, 0x3e, 
// FRAME 10
0x78, 0x7c, 0xb2, 0xce, 0xfe, 0xce, 0xb2, 0x7e, 0x7e, 0xb2, 0xce, 0xfe, 0xce, 0xb2, 0x7c, 0x7c, 
0x1e, 0x3e, 0x4d, 0x73, 0x7f, 0x73, 0x4d, 0x7e, 0x7e, 0x4d, 0x73, 0x7f, 0x73, 0x4d, 0x3e, 0x3e, 
// FRAME 11
0xf8, 0x74, 0xac, 0xd8, 0xb4, 0x6c, 0xd8, 0x34, 0xec, 0x18, 0xf4, 0x08, 0xf0, 0xa0, 0x40, 0x80, 
0x1f, 0x2e, 0x35, 0x1b, 0x2d, 0x36, 0x1b, 0x2c, 0x37, 0x18, 0x2f, 0x10, 0x0f, 0x05, 0x02, 0x01,
};

class Snake
{
  public:
    Snake(byte startX, byte startY, char initDir, byte bodyLength);
    Snake(){};
    byte getX();
    byte getY();
    byte getSpeed();
    char getFacing();
    void updateSnake(byte newX, byte newY);
    void drawSnake(Sprites* sprite);
  private:
    byte x;
    byte y;
    int frame;
    byte len;
    char facing;
    byte moveSpeed = 4;
    byte getBodyPos1(char facing, byte x, byte y, byte bodyIndex);
    byte getBodyPos2(char facing, byte x, byte y, byte bodyIndex);
    byte getFrame(char facing, bool isTail);
};

#endif
