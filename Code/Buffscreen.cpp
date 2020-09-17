#include "Buffscreen.h"
#include <fstream>
using namespace std;

static CHAR_INFO _buff[HEIGHT][WIDTH];

HANDLE _hscr = GetStdHandle(STD_OUTPUT_HANDLE);
static COORD scr_size = {WIDTH, HEIGHT};
static COORD src = {0, 0};
static SMALL_RECT  dest = { 0, 0, WIDTH, HEIGHT};

WORD _getAttribute(COLOR backclr, COLOR textclr)
{
	WORD att = 0;
	if(backclr >= LTBLACK)
	{
		att |= BACKGROUND_INTENSITY;
		backclr = backclr - LTBLACK;
	}
	switch(backclr)
	{
		case RED: att |= BACKGROUND_RED; break;
		case GREEN: att |= BACKGROUND_GREEN; break;
		case BLUE: att |= BACKGROUND_BLUE; break;
		case YELLOW: att |= BACKGROUND_RED | BACKGROUND_GREEN; break;
		case CYAN: att |= BACKGROUND_GREEN | BACKGROUND_BLUE; break;
		case MAGENTA: att |= BACKGROUND_RED | BACKGROUND_BLUE; break;
		case WHITE: att |= BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE; break;
	}

	if(textclr >= LTBLACK)
	{
		att |= FOREGROUND_INTENSITY;
		textclr = textclr - LTBLACK;
	}
	switch(textclr)
	{
		case RED: att |= FOREGROUND_RED; break;
		case GREEN: att |= FOREGROUND_GREEN; break;
		case BLUE: att |= FOREGROUND_BLUE; break;
		case YELLOW: att |= FOREGROUND_RED | FOREGROUND_GREEN; break;
		case CYAN: att |= FOREGROUND_GREEN | FOREGROUND_BLUE; break;
		case MAGENTA: att |= FOREGROUND_RED | FOREGROUND_BLUE; break;
		case WHITE: att |= FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE; break;
	}

	return att;
}

void putncharbuff(char c, COLOR textclr, COLOR backclr, int x, int y, int n)    // 0 <= x, y < WIDTH, HEIGHT
{
    for (int i = 0; i < n; i++)
    {
        _buff[y][x+i].Char.AsciiChar = c;
        _buff[y][x+i].Attributes = _getAttribute(backclr, textclr);
    }
}

void putfilebuff(char s[], COLOR textclr, COLOR backclr, int x, int y)
{

	char c;
	int col = x;
	int row = y;
	ifstream infile;
	infile.open(s);
	while (!infile.eof())
	{
		infile.get(c);
        if (c != ' ' && c != '\n')
            putncharbuff((char)219, textclr, backclr, col, row);
        else putncharbuff(' ', textclr, backclr, col, row);
		col++;
		if (c == '\n')
		{
			row++;
			col = x;
		}
	}
}


char* _choosefile(int number)
{
    char * s;
	switch (number)
	{
		case 0: s = "Number/number0.txt"; break;
		case 1: s = "Number/number1.txt"; break;
		case 2: s = "Number/number2.txt"; break;
		case 3: s = "Number/number3.txt"; break;
		case 4: s = "Number/number4.txt"; break;
		case 5: s = "Number/number5.txt"; break;
		case 6: s = "Number/number6.txt"; break;
		case 7: s = "Number/number7.txt"; break;
		case 8: s = "Number/number8.txt"; break;
		case 9: s = "Number/number9.txt"; break;
	}
	return s;
}
int _daonguoc(int number)
{
	int n;
	int number_nguoc = 0;
	while (number != 0)
	{
		n = number % 10;
		number_nguoc = number_nguoc * 10 + n;
		number /= 10;
	}
	return number_nguoc;
}
void putnumberbuff(int number, COLOR textclr, COLOR backclr, int x, int y)
{
    if (number == 0)
    {
        putfilebuff("Number/number0.txt", textclr, backclr, x, y);
        return;
    }
	int number_nguoc = _daonguoc(number);
	while (number_nguoc != 0)
	{
		int z = number_nguoc % 10;
		putfilebuff(_choosefile(z), textclr, backclr, x, y);
		x +=13;
		number_nguoc /= 10;
	}
	while (number != 0)
	{
		if (number % 10 != 0)
			break;
		else
		{
			putfilebuff("Number/number0.txt", textclr, backclr, x, y);
			x += 13;
		}
		number /= 10;
	}
}

void printbuff()
{
    WriteConsoleOutput(_hscr, (CHAR_INFO *)_buff, scr_size, src, &dest);
}

void hidecursor()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.dwSize = 1; cursor.bVisible = 0;
	SetConsoleCursorInfo(_hscr, &cursor);
}

