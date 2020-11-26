#include <windows.h>
#include <cstdlib>
#include <conio.h>

#include "input.h"
#include "drowV2.0.h"

void madeInput(int& _x, int& _y) {
	switch (input())
	{
	case decision::dup:
		up();
		break;
	case decision::ddown:
		down();
		break;
	case decision::din:
		forward();
		break;
	case decision::dnothing:
		break;
	default:
		break;
	}
}
void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
int input() {
	if (_kbhit)
		switch (pushWay())
		{
		case 'w':
			return decision::dup;
		case 's':
			return decision::ddown;
		case 'a':
			return decision::din;
		default:
			return decision::dnothing;
		}
}
char pushWay() {
	char inp = _getch();
	if (inp == 'w' || inp == 'W' || inp == 72)
		return 'w';
	if (inp == 's' || inp == 'S' || inp == 80)
		return 's';
	if (inp == 'a' || inp == 'A' || inp == 'd' || inp == 'D' || inp == (char)75 || inp == (char)77 || inp == (char)32 || inp == (char)13)
		return 'a';
}