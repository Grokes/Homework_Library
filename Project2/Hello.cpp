#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include "Library.h"
#include "LibMenu.h"

using namespace std;

struct Test
{
	int a;
};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	enum { print = 1, find, sort, edit, load, save, _exit = 7 };
	int SIZE{ 6 };
	int choice{};

	Book* books{};
	//GenArrTest(books);

	while (true)
	{
		system("cls");
		cout << "����� ���������� �����������" << endl
			<< "1. ������� ������ ����\n"
			<< "2. �����\n"
			<< "3. ���������� ����\n"
			<< "4. ������ ��������� � ������\n"
			<< "5. ���������\n"
			<< "6. ���������\n"
			<< "7. �����\n"
			<< "����: ";
		cin >> choice;
		system("cls");

		switch (choice)
		{
		case print:
			if (books == nullptr)
				cout << "������ �� �������\n";
			else
				PrintAllBooks(books, SIZE);
			system("pause");
			continue;
			break;
		case find:
			Menu_Find(books, SIZE);
			break;
		case sort:
			Menu_Sort(books, SIZE);
			break;
		case edit:
			Menu_Edit(books, SIZE);
			break;
		case load:
			Menu_SaveLoad(books, SIZE, LoadBooks);
			break;
		case save:
			Menu_SaveLoad(books, SIZE, SaveBooks);
			break;
		case _exit:
			exit(0);
			break;
		default:
			break;
		}
	}

	

	return 0;
}

