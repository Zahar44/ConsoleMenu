#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "data.h"
#include "input.h"

void addNewMember(Member*& member) {
	gotoxy(0, 0);
	size_t i = 0;
	while (strcmp(member[i].name, ""))
		i++;
	std::cout << "Input some member info: " << '\n' << "First name: ";
	std::cin >> member[i].name;
	std::cout << "Second name: ";
	std::cin >> member[i].sname;
	system("cls");
}
void deleteMember(Member*& member) {
	char tmp[200];
	size_t i = 0;
	bool done = false;
	std::cout << "Type member name: ";
	std::cin >> tmp;
	while (strcmp(member[i].name, ""))
		if (strcmp(member[i].name, tmp) && strcmp(member[i].sname, tmp))
			i++;
		else {
			done = true;
			break;
		}
			
	if (done) {
		while (strcmp(member[i].name, "")) {
			if (strcmp(member[i].name, "")) {
				strcpy_s(member[i].name, 200, member[i + 1].name);
				strcpy_s(member[i].sname, 200, member[i + 1].name);
			}
			else
			{
				strcpy_s(member[i].name, 200, "");
				strcpy_s(member[i].sname, 200, "");
			}
				
			i++;
		}
		std::cout << tmp << " deleted successfully!";
	}
	else
		std::cout << "There is no member with name " << tmp;
	_getch();
	system("cls");
}
void findMember(Member* member) {
	showMembersList(member);
	char tmp[200];
	int i = 0, key = -1;
	gotoxy(0, 0);
	std::cout << "Member name: ";
	std::cin >> tmp;
	while (strcmp(member[i].name, "")) {
		if (strcmp(member[i].name, tmp) && strcmp(member[i].sname, tmp))
			i++;
		else {
			key = i;
			break;
		}
	}
	if (key < 0)
		std::cout << "There no such member!";
	else
	{
		size_t cnt = 0;
		size_t _x = 0, _y = 10;
		while (cnt != i)
		{
			if (strlen(member[cnt].name) > 11 || strlen(member[cnt].sname) > 11)
				if (strlen(member[cnt].name) > strlen(member[cnt].sname))
					_x += strlen(member[cnt].name) + 3;
				else
					_x += strlen(member[cnt].sname) + 3;
			else
				_x += 11;
			if ((cnt + 1) % 3 == 0) {
				_y += 5;
				_x = 0;
			}
			cnt++;
		}
		gotoxy(_x, _y);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 158);
		std::cout << "Member #" << i + 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 144);
	}
	_getch();
	system("cls");
}
void showMembersList(Member* member) {
	size_t cnt = 0;
	size_t _x = 0, _y = 10;
	while (strcmp(member[cnt].name, ""))
	{
		gotoxy(_x, _y);
		std::cout << "Member #" << cnt + 1;
		gotoxy(_x, _y + 1);
		std::cout << member[cnt].name;
		gotoxy(_x, _y + 2);
		std::cout << member[cnt].sname;
		if (strlen(member[cnt].name) > 11 || strlen(member[cnt].sname) > 11)
			if (strlen(member[cnt].name) > strlen(member[cnt].sname))
				_x += strlen(member[cnt].name) + 3;
			else
				_x += strlen(member[cnt].sname) + 3;
		else
			_x += 11;

		if ((cnt + 1) % 3 == 0) {
			_y += 5;
			_x = 0;
		}
		cnt++;
	}
}

void exportToFile(Member* member) {
	char fileCore[200] = {"./Files/"};
	char fileName[200];
	std::cout << "Type file name: ";
	std::cin >> fileName;
	strcat_s(fileName, 200, ".txt");
	strcat_s(fileCore, 200, fileName);
	FILE* fptr;
	fopen_s(&fptr, fileCore, "w");
	if (fptr == NULL)
	{
		printf("Error!");
		exit(1);
	}
	else {
		size_t i = 0;
		while (strcmp(member[i].name, ""))
		{
			fprintf_s(fptr, "%s%d%c%s%c%s%c", "Member #", i + 1, '\n', member[i].name, '\n', member[i].sname, '\n');
			i++;
		}
	}
	fclose(fptr);
	std::cout << "File created seccessufully!";
	_getch();
	system("cls");
}
void importfromFile(Member* member) {
	char fileCore[200] = { "./Files/" };
	char fileName[200];
	std::cout << "Type file name: ";
	std::cin >> fileName;
	strcat_s(fileName, 200, ".txt");
	strcat_s(fileCore, 200, fileName);
	FILE* fptr;
	fopen_s(&fptr, fileCore, "r+");
	if (fptr == NULL)
	{
		printf("Error!");
		exit(1);
	}
	else {
		size_t i = 0;
		fseek(fptr, 0L, SEEK_SET);
		int c = getc(fptr);
		while (c != EOF)
		{
			char tmp[200];
			putchar(c);
			fscanf_s(fptr, "%s%s", tmp, 200, tmp, 200);
			fscanf_s(fptr, "%c", tmp, 200);
			fscanf_s(fptr, "%s", member[i].name, 200);
			fscanf_s(fptr, "%c", tmp, 200);
			fscanf_s(fptr, "%s", member[i].sname, 200);
			c = getc(fptr);
			i++;
		}
	}
	fclose(fptr);
	system("cls");
	std::cout << "Information imported successfully!";
	_getch();
	system("cls");
}