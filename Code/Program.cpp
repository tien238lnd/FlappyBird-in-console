#include "Pillar.h"
#include "Control.h"
#include "Draw.h"
#include "Bird.h"

int main()
{
    start_screen();
    start:
    int score = 0;

    PILLAR pillars[2];
    BIRD bird;
    init_pillars(pillars);
    init_bird(bird);

    putnumberbuff(score, RED, LTYELLOW, 1, HEIGHT - GROUND_H + 3);
    putfilebuff("Text/Pause.txt", RED, LTYELLOW, 28, HEIGHT - GROUND_H + 3);
    printbuff();
   // int now = clock();
   // int moving_time = 10;
    while (true)
    {
        delay(25);
        falling_bird(bird);
        moving_pillars(pillars);
        printbuff();
      //  moving_time += 10;

        if (_kbhit())
        {
            int key = _getch();
            if (key == 32) flapping_bird(bird);
            else
            {
                button();
                putfilebuff("Text/Continue.txt", RED, LTYELLOW, 28, HEIGHT - GROUND_H + 3);
                printbuff();
                while (!_getch()){};
                putfilebuff("Text/Pause.txt", RED, LTYELLOW, 28, HEIGHT - GROUND_H + 3);
                button();
            }
        }

        if (pass(pillars))
        {
            score++;
            scored();
            putnumberbuff(score, RED, LTYELLOW, 1, HEIGHT - GROUND_H + 3);
        }

        if (collide(bird, pillars))
        {
            collide();
            game_over(score);
            break;
        }
     //   now = clock();
    }
    goto start;
}
