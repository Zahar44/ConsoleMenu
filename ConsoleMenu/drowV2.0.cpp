#include <iostream>

#include <Windows.h>
#include <conio.h>

#include "drowV2.0.h"
#include "input.h"
#include "data.h"

//#define DEBUG 

#define WHITE_CONSOLE_TEXT 158
#define DEFOULT_CONSOLE_TEXT 144

int y = 0, x = Menu::MainMenu, previousX, previousY, backToX;
bool isForward = false;
bool firstTry = true;

void up() {
	y--;
}
void down() {
	y++;
}
void forward() {
	isForward = true;
} 

void chekField(int& _x, int& _y, Field** menu, Member*& member) {
#ifdef DEBUG
	if (!menu[x][y].isInputTable)
	{
		gotoxy(0, 0);
		std::cout << "x, y is input    ";
	}
	else
	{
		gotoxy(0, 0);
		std::cout << "x, y is not input";
	}

	if (!menu[previousX][previousY].isInputTable)
	{
		gotoxy(0, 1);
		std::cout << "pre (x, y) is input    ";
	}
	else
	{
		gotoxy(0, 1);
		std::cout << "pre (x, y) is not input";
	}
#endif // DEBUG

	if (isForward)
		changeMenu(menu);

	size_t menuCnt = findMenuCnt(menu);

	menuOverrun(_x, _y, menuCnt);

	if (!menu[previousX][previousY].isInputTable) {
		drowInfMenu(_x, _y, menu, menuCnt);
		madeInput(_x, _y);
	}
	else 
		drowWithInput(_x, _y, menu, member, menuCnt);

}

void menuOverrun(int& _x, int& _y, size_t menuCnt) {
	if (y > int(menuCnt - 1))
		y = 0;
	if (y < 0) 
		y += menuCnt;
}
void menuAnim(int& _x, int& _y, Field** menu, size_t menuCnt) {
	menuOverrun(_x, _y, menuCnt);
	gotoxy(_x, _y + y);
	for (size_t i = 0; i < strlen(menu[x][y].label); i++)
		std::cout << " ";
	gotoxy(_x, _y + y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE_CONSOLE_TEXT);
	std::cout << menu[x][y].label;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFOULT_CONSOLE_TEXT);
	gotoxy(_x, _y + y);
}
void drowInfMenu(int& _x, int& _y, Field** menu, size_t& menuCnt) {
	size_t tmp = 0;
	
	drowFrame(_x, _y, menu[x], menuCnt);

	for (size_t i = 0; i < menuCnt; i++)
	{
		gotoxy(_x, _y++);
		tmp++;
		std::cout << menu[x][i].label;
	}
	_y -= tmp;
	menuAnim(_x, _y, menu, menuCnt);
}
void drowFrame(int _x, int _y, Field* menu, size_t menuCnt) {
	size_t x = _x;
	size_t y = _y;
	gotoxy(x - 1, y - 1);
	for (size_t i = 0; i < findMaxLen(menu) + 2; i++)
		std::cout << char(205);
	gotoxy(x - 1, y + menuCnt);
	for (size_t i = 0; i < findMaxLen(menu) + 2; i++)
		std::cout << char(205);

	for (size_t i = _y; i < _y + menuCnt; i++)
	{
		gotoxy(_x - 1, i);
		std::cout << char(186);
	}

	for (size_t i = _y; i < _y + menuCnt; i++)
	{
		gotoxy(x + findMaxLen(menu), i);
		std::cout << char(186);
	}
	gotoxy(x - 1, y - 1);
	std::cout << char(201);
	gotoxy(x - 1, y + menuCnt);
	std::cout << char(200);
	gotoxy(x + findMaxLen(menu), y - 1);
	std::cout << char(187);
	gotoxy(x + findMaxLen(menu), y + menuCnt);
	std::cout << char(188);
}

void drowWithInput(int& _x, int& _y, Field** menu, Member*& member, size_t& menuCnt) {
	system("cls");
	inputData(menu, member);
	previousY = menuCnt;
}

void inputData(Field** menu, Member*& member) {
	switch (menu[x][y].id)
	{
	case ExportToFile_m:
		exportToFile(member);
		break;
	case ImportFromFile_m:
		importfromFile(member);
		break;
	case AddNewMember_m:
		addNewMember(member);
		break;
	case DeleteMember_m:
		deleteMember(member);
		break;
	case FindMember_m:
		findMember(member);
		break;
	default:
		break;
	}
}

void changeMenu(Field** menu) {
	system("cls");
	switch (menu[x][y].id)
	{
	case EditDatabase_m:
		backToX = x;
		x = Menu::EditMemberMenu;
		break;
	case ExportToFile_m:
		previousX = x;
		previousY = y;
		break;
	case ImportFromFile_m:
		previousX = x;
		previousY = y;
		break;
	case Exit_m:
		exit(1);
		break;
	case ShowAllMembers_m:
		previousX = x;
		previousY = y;
		break;
	case AddNewMember_m:
		previousX = x;
		previousY = y;
		break;
	case DeleteMember_m:
		previousX = x;
		previousY = y;
		break;
	case FindMember_m:
		previousX = x;
		previousY = y;
		break;
	case Back:
		x = backToX;
		y = findMenuCnt(menu);
		break;
	default:
		break;
	}
	isForward = false;
}

size_t findMaxLen(Field* menu) {
	size_t max = 0, i = 0;
	while(strcmp(menu[i].label, "*"))
	{
		if (max < strlen(menu[i].label))
			max = strlen(menu[i].label);
		i++;
	}
	return max;
}
size_t findMenuCnt(Field** menu) {
	size_t menuCnt = 0;
	while (strcmp(menu[x][menuCnt++].label, "*")) {}
	return menuCnt - 1;
}