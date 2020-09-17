#ifndef MY_CONTROL
#define MY_CONTROL

#include <ctime>
#include <conio.h>
#include "Sound.h"
#include "Draw.h"


struct Point
{
    int x, y;
};

struct BIRD
{
    int t;
    int y;
    Point edgepoint[100];
};

struct PILLAR
{
    Point edgepoint[400];
    int x;
    int y;
};


void delay(int t);
bool collide(BIRD bird, PILLAR pillars[]);
bool pass(PILLAR pillars[]);
void start_screen();
void game_over(int score);

#endif // MY_CONTROL
