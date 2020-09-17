#ifndef MY_BUFF
#define MY_BUFF
#define _WIN32_WINNT 0x0500
#include <Windows.h>
typedef	int COLOR;
#define	BLACK			0
#define	RED		    	1
#define	BLUE			2
#define	GREEN			3
#define	YELLOW		    4
#define	MAGENTA		    5
#define	CYAN			6
#define WHITE			7
#define	LTBLACK		    8
#define	LTRED			9
#define	LTBLUE		    10
#define	LTGREEN		    11
#define	LTYELLOW		12
#define	LTMAGENTA		13
#define	LTCYAN		    14
#define LTWHITE		    15

#define WIDTH 180
#define HEIGHT 140
#define TOP 0
#define GROUND_H 15
#define GAP_PILLAR 45
#define BGD_CLR LTCYAN
#define PILLAR_CLR GREEN

void putncharbuff(char c, COLOR textclr, COLOR backclr, int x, int y, int n = 1);

void putfilebuff(const char* s, COLOR textclr, COLOR backclr, int x, int y);

void putnumberbuff(int number, COLOR textclr, COLOR backclr, int x, int y);

void printbuff();

void hidecursor();

#endif // MY_BUFF

