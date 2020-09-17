#include "Control.h"
#include <fstream>
using namespace std;

void delay(int t)        // delay t miliseconds
{
	double s = clock();
	while (clock() - s < t);
}

bool collide(BIRD bird, PILLAR pillars[])
{
    if (bird.y + 18 >= HEIGHT - GROUND_H + TOP) return 1;
    if (bird.y <= 2) return 1;
    for (int i = 0; i <= 1; i++)
    {
        if (12 < pillars[i].x && pillars[i].x < 58)       // bird.x - pillar.width, bird.x + bird.width
            for (int p = 1; p <= pillars[i].edgepoint[0].x; p++)
                for (int b = 1; b <= bird.edgepoint[0].x; b++)
                    if (pillars[i].edgepoint[p].x == bird.edgepoint[b].x &&
                        pillars[i].edgepoint[p].y == bird.edgepoint[b].y)
                        return 1;
    }
    return 0;
}

bool pass(PILLAR pillars[])
{
    for (int i = 0; i <= 1; i++)
        if ( 10 <= pillars[i].x && pillars[i].x <= 14) return 1;
    return 0;
}


int _GetScore()
{
	ifstream infile("BestScore.txt");
	int bestscore;
	infile >> bestscore;
	infile.close();
	return bestscore;
}
void _SaveScore(int bestscore)
{

	ofstream outfile("BestScore.txt");
	outfile << bestscore;
	outfile.close();
}

void start_screen()
{
    initsound();
    hidecursor();
    init_screen();
    while ((getch() != 13));
    button();
    return;
}

void game_over(int score)
{
    int bestscore = _GetScore();
    if (score > bestscore)
    {
         bestscore = score;
        _SaveScore(bestscore);
    }
    putfilebuff("Text/Gameover.txt", RED, BGD_CLR, 0, 20);
    putnumberbuff(score, RED, BGD_CLR, 135, 41);
    putnumberbuff(bestscore, RED, BGD_CLR, 135, 53);
    putfilebuff("Text/Again.txt", RED, LTYELLOW, 0, HEIGHT - GROUND_H + 3);
    printbuff();
    while ((getch() != 13));
    button();
    return;


}

