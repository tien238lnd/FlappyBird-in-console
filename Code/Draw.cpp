#include "Draw.h"

void draw_background()
{
    for (int i = 0; i < GROUND_H -1; i++)
        putncharbuff(' ', LTYELLOW, LTYELLOW, 0, HEIGHT - i + TOP -1, WIDTH);

    for (int i = 0; i <= HEIGHT - GROUND_H; i++)
        putncharbuff(' ', BGD_CLR, BGD_CLR, 0, i + TOP, WIDTH);
}

void init_screen()
{
    draw_background();
    putfilebuff("Text/Flappybird.txt", YELLOW, BGD_CLR, 20, 20);
    putfilebuff("Text/Enter.txt", RED, BGD_CLR, 28, 50);
    printbuff();
}
