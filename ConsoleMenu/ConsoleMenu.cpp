#include <iostream>
#include <fstream>
#include <stdlib.h>

#include <Windows.h>

#include "drowV2.0.h";
#include "input.h";
#include "field.h"
#include "data.h"


#define CONSOLE_TEXT_COLOR "Color 9F"

#define START_LIST_X 50
#define START_LIST_Y 5

#define MAX_MEMBERS 10

int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 144);
	system("cls");
	int _x = START_LIST_X, _y = START_LIST_Y;

	Field** menu = initAllFields();
	Member* member = new Member[MAX_MEMBERS];
	for (size_t i = 0; i < MAX_MEMBERS; i++)
	{
		strcpy_s(member[i].name, 200, "");
		strcpy_s(member[i].sname, 200, "");
	}

	while (true)
	{
		chekField(_x, _y, menu, member);
	}

	deleteAllFields(menu);

	std::cout << std::endl;
	system("pause");
}
