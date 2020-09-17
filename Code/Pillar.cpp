#include "Pillar.h"
#include <cstdlib>

static int w = 25; // width of pillar
static int h = 10; // height of cap of pillar

static void _update_edge_pillars_coord(PILLAR pillars[])
{
    for (int i = 0; i <= 1; i++)
    {
        if (12 < pillars[i].x && pillars[i].x < 58)
        {
            int count = 0;
            int y = TOP;
            for ( ; y <= pillars[i].y - h; y++)
            {
                int x = 1;
                count++;
                pillars[i].edgepoint[count].x = pillars[i].x + x;
                pillars[i].edgepoint[count].y = y;
            }

            for ( ; y <= pillars[i].y - 1; y++)
            {
                int x = 0;
                count++;
                pillars[i].edgepoint[count].x = pillars[i].x + x;
                pillars[i].edgepoint[count].y = y;
            }

            for (int x = 0; x <= w-1; x++)
            {
                count++;
                pillars[i].edgepoint[count].x = pillars[i].x + x;
                pillars[i].edgepoint[count].y = y;
            }

            y += GAP_PILLAR + 1;
            for (int x = 0; x <= w-1; x++)
            {
                count++;
                pillars[i].edgepoint[count].x = pillars[i].x + x;
                pillars[i].edgepoint[count].y = y;
            }

            for (y++; y <= pillars[i].y + GAP_PILLAR + h; y++)
            {
                int x = 0;
                count++;
                pillars[i].edgepoint[count].x = pillars[i].x + x;
                pillars[i].edgepoint[count].y = y;
            }

            for ( ; y <= HEIGHT - GROUND_H + TOP; y++)
            {
                int x = 1;
                count++;
                pillars[i].edgepoint[count].x = pillars[i].x + x;
                pillars[i].edgepoint[count].y = y;
            }

            pillars[i].edgepoint[0].x = count;               // số point được lưu ở point[0].x
        }
    }
}

void _putpillar2buff(PILLAR pillars[], char c)   // hàm vẽ hoặc xóa cột trên buffscr
{
    for(int i = 0; i <= 1; i++)
    {
        int y = TOP;
        if (pillars[i].x > WIDTH - 1){}
        else if (pillars[i].x < 0)
        {
            for ( ; y <= pillars[i].y - h; y++)
                putncharbuff(c, PILLAR_CLR, BGD_CLR, 0, y, w + pillars[i].x - 1);

            for ( ; y <= pillars[i].y; y++)
                putncharbuff(c, PILLAR_CLR, BGD_CLR, 0, y, w + pillars[i].x);

            for (y += GAP_PILLAR; y <= pillars[i].y + GAP_PILLAR + h; y++)
                putncharbuff(c, PILLAR_CLR, BGD_CLR, 0, y, w + pillars[i].x);

            for ( ; y <= HEIGHT - GROUND_H + TOP; y++)
                putncharbuff(c, PILLAR_CLR, BGD_CLR, 0, y, w + pillars[i].x - 1);
        }
        else if (pillars[i].x + w > WIDTH)
        {
            for ( ; y <= pillars[i].y - h; y++)
                putncharbuff(c, PILLAR_CLR, BGD_CLR, pillars[i].x + 1, y, WIDTH - pillars[i].x - 1);

            for ( ; y <= pillars[i].y; y++)
                putncharbuff(c, PILLAR_CLR, BGD_CLR, pillars[i].x, y, WIDTH - pillars[i].x);


            for (y += GAP_PILLAR; y <= pillars[i].y + GAP_PILLAR + h; y++)
                putncharbuff(c, PILLAR_CLR, BGD_CLR, pillars[i].x, y, WIDTH - pillars[i].x);

            for ( ; y <= HEIGHT - GROUND_H + TOP; y++)
                putncharbuff(c, PILLAR_CLR, BGD_CLR, pillars[i].x + 1, y, WIDTH - pillars[i].x -1);
        }
        else
        {
            for ( ; y <= pillars[i].y - h; y++)
               putncharbuff(c, PILLAR_CLR, BGD_CLR, pillars[i].x + 1, y, w-2);

            for ( ; y <= pillars[i].y; y++)
                putncharbuff(c, PILLAR_CLR, BGD_CLR, pillars[i].x, y, w);

            for (y += GAP_PILLAR; y <= pillars[i].y + GAP_PILLAR + h; y++)
                putncharbuff(c, PILLAR_CLR, BGD_CLR, pillars[i].x, y, w);

            for ( ; y <= HEIGHT - GROUND_H + TOP; y++)
                putncharbuff(c, PILLAR_CLR, BGD_CLR, pillars[i].x + 1, y, w-2);
        }
    }
}

static void _reset_y(PILLAR &pillar)
{
    int min = 16;
    int max = HEIGHT - GROUND_H - GAP_PILLAR - min;
    pillar.y = rand()%(max - min + 1) + min + TOP;
}

void init_pillars(PILLAR pillars[])
{
    pillars[0].x = 185;
    pillars[1].x = 185 + WIDTH/2 + w/2;
    srand(time(NULL));
    _reset_y(pillars[0]);
    _reset_y(pillars[1]);
}

void moving_pillars(PILLAR pillars[])
{
    _putpillar2buff(pillars, ' ');
    pillars[0].x-=5;
    pillars[1].x-=5;

    if (pillars[0].x <= -w)
    {
        _reset_y(pillars[0]);
        pillars[0].x = WIDTH - 1;
    }
    else if (pillars[1].x <= -w)
    {
        _reset_y(pillars[1]);
        pillars[1].x = WIDTH - 1;
    }

    _update_edge_pillars_coord(pillars);
    _putpillar2buff(pillars, (char)219);
}

