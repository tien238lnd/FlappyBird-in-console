#include <windows.h>
#include <cstdlib>
#include "Sound.h"
#include "Control.h"
#pragma comment(lib, "Winmm.lib")

void initsound()
{
    mciSendString("open Sound/collide.mp3 type mpegvideo alias mp3", NULL, 0, NULL);
    mciSendString("open Sound/flap.mp3 type mpegvideo alias mp3", NULL, 0, NULL);
    mciSendString("open Sound/button.mp3 type mpegvideo alias mp3", NULL, 0, NULL);
    mciSendString("open Sound/score.mp3 type mpegvideo alias mp3", NULL, 0, NULL);
}

void collide()
{
    mciSendString("play Sound/collide.mp3 wait", NULL, 0, NULL);
}


void flap()
{
    mciSendString("stop Sound/flap.mp3", NULL, 0, NULL);
    mciSendString("play Sound/flap.mp3", NULL, 0, NULL);

}

void button()
{
     mciSendString("play Sound/button.mp3", NULL, 0, NULL);
}


void scored()
{
    mciSendString("play Sound/score.mp3", NULL, 0, NULL);
}
