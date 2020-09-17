#include "Bird.h"
#include <cmath>

static int bird_figure_01[16][16] ={{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                   { 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0},
                                   { 0, 0, 0, 9, 9, 9, 1, 1, 1, 1, 1, 9, 9, 0, 0, 0},
                                   { 0, 0, 9, 9, 1, 1, 2, 2, 2, 1, 5, 1, 9, 9, 0, 0},
                                   { 9, 9, 9, 1, 2, 2, 2, 2, 1, 5, 5, 5, 1, 9, 9, 0},
                                   { 9, 1, 1, 1, 1, 2, 2, 2, 1, 5, 5, 1, 5, 1, 9, 0},
                                   { 1, 5, 5, 5, 5, 1, 2, 2, 1, 5, 5, 1, 5, 1, 9, 0},
                                   { 1, 5, 5, 5, 5, 5, 1, 2, 2, 1, 5, 5, 5, 1, 9, 9},
                                   { 1, 5, 5, 5, 5, 5, 1, 2, 2, 2, 1, 1, 1, 1, 1, 9},
                                   { 9, 1, 5, 5, 5, 1, 2, 2, 2, 1, 4, 4, 4, 4, 4, 1},
                                   { 9, 9, 1, 1, 1, 3, 3, 3, 1, 4, 1, 1, 1, 1, 1, 9},
                                   { 0, 9, 1, 3, 3, 3, 3, 3, 3, 1, 4, 4, 4, 4, 1, 9},
                                   { 0, 9, 9, 1, 1, 3, 3, 3, 3, 3, 1, 1, 1, 1, 9, 9},
                                   { 0, 0, 9, 9, 9, 1, 1, 1, 1, 1, 9, 9, 9, 9, 9, 0},
                                   { 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0},
                                   { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};


static int bird_figure_02[16][16] ={{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                   { 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0},
                                   { 0, 0, 0, 9, 9, 9, 1, 1, 1, 1, 1, 9, 9, 0, 0, 0},
                                   { 0, 0, 9, 9, 1, 1, 2, 2, 2, 1, 5, 1, 9, 9, 0, 0},
                                   { 0, 9, 9, 1, 2, 2, 2, 2, 1, 5, 5, 5, 1, 9, 9, 0},
                                   { 9, 9, 1, 2, 2, 2, 2, 2, 1, 5, 5, 1, 5, 1, 9, 0},
                                   { 9, 1, 2, 2, 2, 2, 2, 2, 1, 5, 5, 1, 5, 1, 9, 0},
                                   { 9, 1, 2, 2, 2, 2, 2, 2, 2, 1, 5, 5, 5, 1, 9, 9},
                                   { 9, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 9},
                                   { 1, 5, 5, 5, 5, 5, 1, 2, 2, 1, 4, 4, 4, 4, 4, 1},
                                   { 1, 5, 5, 5, 5, 1, 3, 3, 1, 4, 1, 1, 1, 1, 1, 9},
                                   { 1, 5, 5, 5, 1, 3, 3, 3, 3, 1, 4, 4, 4, 4, 1, 9},
                                   { 9, 1, 1, 1, 1, 3, 3, 3, 3, 3, 1, 1, 1, 1, 9, 9},
                                   { 9, 9, 9, 9, 9, 1, 1, 1, 1, 1, 9, 9, 9, 9, 9, 0},
                                   { 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0},
                                   { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

static int bird_figure_11[16][16] ={{ 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0},
                                    { 0, 0, 0, 9, 9, 9, 1, 1, 1, 1, 9, 9, 0, 0, 0, 0},
                                    { 0, 0, 9, 9, 1, 1, 5, 5, 5, 5, 1, 9, 9, 0, 0, 0},
                                    { 0, 9, 9, 1, 2, 1, 5, 5, 1, 5, 5, 1, 9, 9, 9, 9},
                                    { 0, 9, 1, 2, 2, 1, 5, 5, 5, 1, 5, 5, 1, 4, 1, 9},
                                    { 9, 9, 1, 2, 2, 2, 1, 5, 5, 5, 5, 1, 4, 1, 4, 9},
                                    { 9, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 4, 1, 4, 1, 9},
                                    { 1, 5, 5, 5, 5, 1, 2, 2, 2, 1, 4, 1, 4, 1, 9, 9},
                                    { 1, 5, 5, 5, 5, 1, 2, 2, 3, 1, 4, 4, 1, 9, 9, 0},
                                    { 1, 1, 5, 5, 1, 2, 3, 3, 3, 3, 1, 3, 1, 9, 0, 0},
                                    { 9, 1, 5, 1, 2, 3, 3, 3, 3, 3, 3, 1, 9, 9, 0, 0},
                                    { 9, 9, 1, 1, 3, 3, 3, 3, 3, 3, 1, 9, 9, 0, 0, 0},
                                    { 0, 9, 9, 9, 1, 3, 3, 3, 3, 1, 9, 9, 0, 0, 0, 0},
                                    { 0, 0, 0, 9, 9, 1, 1, 1, 1, 9, 9, 0, 0, 0, 0, 0},
                                    { 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0},
                                    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

static int bird_figure_12[16][16] ={{ 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0},
                                    { 0, 0, 0, 9, 9, 9, 1, 1, 1, 1, 9, 9, 0, 0, 0, 0},
                                    { 0, 0, 9, 9, 1, 1, 5, 5, 5, 5, 1, 9, 9, 0, 0, 0},
                                    { 0, 9, 9, 1, 2, 1, 5, 5, 1, 5, 5, 1, 9, 9, 9, 9},
                                    { 0, 9, 1, 2, 2, 1, 5, 5, 5, 1, 5, 5, 1, 4, 1, 9},
                                    { 9, 9, 1, 2, 2, 2, 1, 5, 5, 5, 5, 1, 4, 1, 4, 9},
                                    { 9, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 4, 1, 4, 1, 9},
                                    { 9, 1, 2, 2, 2, 2, 2, 2, 2, 1, 4, 1, 4, 1, 9, 9},
                                    { 9, 1, 2, 2, 1, 1, 2, 2, 3, 1, 4, 4, 1, 9, 9, 0},
                                    { 9, 1, 1, 1, 5, 5, 1, 3, 3, 3, 1, 3, 1, 9, 0, 0},
                                    { 9, 9, 1, 5, 5, 5, 1, 3, 3, 3, 3, 1, 9, 9, 0, 0},
                                    { 9, 1, 5, 5, 5, 5, 1, 3, 3, 3, 1, 9, 9, 0, 0, 0},
                                    { 9, 1, 5, 5, 5, 5, 1, 3, 3, 1, 9, 9, 0, 0, 0, 0},
                                    { 9, 9, 1, 5, 5, 1, 1, 1, 1, 9, 9, 0, 0, 0, 0, 0},
                                    { 0, 9, 9, 1, 1, 1, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0},
                                    { 0, 0, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

static int bird_figure_21[16][16] ={{ 0, 0, 0, 0, 9, 9, 1, 1, 1, 9, 9, 0, 0, 0, 0, 0},
                                    { 0, 0, 0, 9, 9, 1, 1, 5, 5, 1, 9, 9, 9, 0, 0, 0},
                                    { 0, 0, 0, 9, 1, 5, 5, 5, 5, 1, 1, 1, 9, 9, 0, 0},
                                    { 0, 0, 9, 9, 1, 1, 5, 5, 5, 1, 2, 2, 1, 9, 9, 0},
                                    { 0, 9, 9, 1, 3, 2, 1, 5, 5, 1, 2, 2, 2, 1, 9, 0},
                                    { 0, 9, 1, 3, 3, 3, 2, 1, 1, 2, 2, 1, 1, 1, 9, 9},
                                    { 0, 9, 1, 3, 3, 3, 3, 2, 2, 2, 1, 5, 5, 5, 1, 9},
                                    { 0, 9, 1, 3, 3, 3, 3, 2, 2, 1, 5, 5, 5, 5, 1, 9},
                                    { 0, 9, 1, 3, 3, 3, 3, 3, 2, 1, 5, 5, 1, 5, 1, 9},
                                    { 0, 9, 9, 1, 3, 3, 3, 1, 1, 1, 5, 1, 5, 5, 1, 9},
                                    { 0, 0, 9, 9, 1, 3, 1, 4, 4, 1, 5, 5, 5, 1, 9, 9},
                                    { 0, 0, 0, 9, 9, 1, 3, 4, 1, 4, 1, 5, 1, 9, 9, 0},
                                    { 0, 0, 0, 0, 9, 9, 1, 1, 4, 1, 4, 1, 9, 9, 0, 0},
                                    { 0, 0, 0, 0, 0, 9, 9, 9, 1, 4, 1, 4, 9, 0, 0, 0},
                                    { 0, 0, 0, 0, 0, 0, 0, 9, 9, 1, 4, 1, 9, 0, 0, 0},
                                    { 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 0, 0, 0}};

static int bird_figure_22[16][16] ={{ 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0},
                                    { 0, 9, 9, 1, 1, 9, 1, 1, 1, 1, 9, 9, 9, 0, 0, 0},
                                    { 9, 9, 1, 5, 5, 1, 1, 2, 2, 2, 1, 1, 9, 9, 0, 0},
                                    { 9, 1, 5, 5, 5, 5, 1, 2, 2, 2, 2, 2, 1, 9, 9, 0},
                                    { 9, 1, 5, 5, 5, 5, 5, 1, 2, 2, 2, 2, 2, 1, 9, 0},
                                    { 9, 1, 1, 5, 5, 5, 5, 1, 2, 2, 2, 1, 1, 1, 9, 9},
                                    { 9, 9, 1, 1, 1, 1, 1, 2, 2, 2, 1, 5, 5, 5, 1, 9},
                                    { 0, 9, 1, 3, 3, 3, 3, 2, 2, 1, 5, 5, 5, 5, 1, 9},
                                    { 0, 9, 1, 3, 3, 3, 3, 3, 2, 1, 5, 5, 1, 5, 1, 9},
                                    { 0, 9, 9, 1, 3, 3, 3, 1, 1, 1, 5, 1, 5, 5, 1, 9},
                                    { 0, 0, 9, 9, 1, 3, 1, 4, 4, 1, 5, 5, 5, 1, 9, 9},
                                    { 0, 0, 0, 9, 9, 1, 3, 4, 1, 4, 1, 5, 1, 9, 9, 0},
                                    { 0, 0, 0, 0, 9, 9, 1, 1, 4, 1, 4, 1, 9, 9, 0, 0},
                                    { 0, 0, 0, 0, 0, 9, 9, 9, 1, 4, 1, 4, 9, 0, 0, 0},
                                    { 0, 0, 0, 0, 0, 0, 0, 9, 9, 1, 4, 1, 9, 0, 0, 0},
                                    { 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 0, 0, 0}};


static int bird_figure_3[16][16] = {{ 0, 0, 0, 0, 9, 9, 1, 1, 9, 9, 9, 0, 0, 0, 0, 0},
                                    { 0, 0, 0, 9, 9, 1, 5, 5, 1, 1, 9, 9, 0, 0, 0, 0},
                                    { 0, 0, 9, 9, 1, 1, 5, 5, 1, 2, 1, 9, 9, 0, 0, 0},
                                    { 0, 9, 9, 1, 3, 1, 5, 5, 1, 2, 2, 1, 9, 9, 0, 0},
                                    { 0, 9, 1, 3, 3, 1, 5, 5, 1, 2, 2, 2, 1, 9, 9, 0},
                                    { 0, 9, 1, 3, 3, 3, 1, 1, 2, 2, 2, 2, 2, 1, 9, 0},
                                    { 0, 9, 1, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 1, 9, 0},
                                    { 0, 9, 1, 3, 3, 1, 2, 2, 2, 1, 1, 1, 2, 1, 9, 0},
                                    { 0, 9, 1, 3, 1, 4, 1, 2, 1, 5, 5, 5, 1, 1, 9, 0},
                                    { 0, 9, 9, 1, 4, 1, 4, 1, 5, 5, 5, 5, 5, 1, 9, 0},
                                    { 0, 0, 9, 1, 4, 1, 4, 1, 5, 1, 1, 5, 1, 9, 9, 0},
                                    { 0, 0, 9, 1, 4, 1, 4, 1, 5, 5, 5, 1, 9, 9, 0, 0},
                                    { 0, 0, 9, 1, 4, 1, 4, 1, 1, 1, 1, 9, 9, 0, 0, 0},
                                    { 0, 0, 9, 9, 1, 1, 4, 1, 9, 9, 9, 9, 0, 0, 0, 0},
                                    { 0, 0, 0, 0, 9, 9, 1, 9, 9, 0, 0, 0, 0, 0, 0, 0},
                                    { 0, 0, 0, 0, 0, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0}};

static double v;
static int s, angle, wing, x = 40; // s = 1 or -1, angle = 0 or 1 or -1 or -2
static const int g = 2500;

void _putbird2buff_and_update_edge_coord(BIRD &bird, char c)
{
    int (*bird_figure)[16] = new int[16][16];
    switch(angle)
    {
        case -2: bird_figure = bird_figure_3;
                 break;
        case -1: if (wing == 1)
                    bird_figure = bird_figure_21;
                 else
                    bird_figure = bird_figure_22;
                 break;
        case 0: if (wing == 1)
                    bird_figure = bird_figure_01;
                 else
                    bird_figure = bird_figure_02;
                 break;
        case 1: if (wing == 1)
                    bird_figure = bird_figure_11;
                 else
                    bird_figure = bird_figure_12;
                 break;
    }

    int count = 1;
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			switch (bird_figure[i][j])
			{
			case 0: break;
			case 1:
				putncharbuff(c, BLACK, BGD_CLR, j + x, i + bird.y); break;
			case 2:
				putncharbuff(c, LTYELLOW, BGD_CLR, j + x, i + bird.y); break;
			case 3:
				putncharbuff(c, YELLOW, BGD_CLR, j + x, i + bird.y); break;
			case 4:
				putncharbuff(c, RED, BGD_CLR, j + x, i + bird.y); break;
			case 5:
				putncharbuff(c, WHITE, BGD_CLR, j + x, i + bird.y); break;
			case 9:
				bird.edgepoint[count].x = j + x;
				bird.edgepoint[count].y = i + bird.y;
				count++; break;
			}
		}
	}
    bird.edgepoint[0].x = count;
}

static void _update(BIRD &bird)                                 //ok
{
    double t;           // đơn vị second

    t = 0.015; //s
    s = (int)round(v*t + g*t*t/2);
    v += g*t;
    bird.y += s;
    wing = -wing;
    if (v < 0) angle = 1;
    else if (v >= 250)
        angle = -2;
    else if (v >= 100)
        angle = -1;
    else if (v >= 0)
        angle = 0;
}

void init_bird(BIRD &bird)                                 //ok
{
    bird.t = 0;
    v = 0;
    wing = 1;
    angle = 0;
    bird.y = 60;
    draw_background();
    putfilebuff("Text/Getready.txt", YELLOW, BGD_CLR, 10, 30);
    do
    {
        _putbird2buff_and_update_edge_coord(bird,(char)219);
        printbuff();
        delay(100);
        _putbird2buff_and_update_edge_coord(bird, ' ');
        wing = -wing;
   } while (!_kbhit() || (_getch() != 32));
   draw_background();
    _update(bird);
}

void falling_bird(BIRD &bird)                              //ok
{
    _putbird2buff_and_update_edge_coord(bird, ' ');
    _update(bird);
    _putbird2buff_and_update_edge_coord(bird, (char)219);

}

void flapping_bird(BIRD &bird)                             //ok
{
    v = -300;
    flap();
}

