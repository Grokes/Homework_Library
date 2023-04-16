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
		cout << "Центр управления библиотекой" << endl
			<< "1. Вывести список книг\n"
			<< "2. Поиск\n"
			<< "3. Сортировка книг\n"
			<< "4. Внести изменения в данные\n"
			<< "5. Загрузить\n"
			<< "6. Сохранить\n"
			<< "7. Выход\n"
			<< "Ввод: ";
		cin >> choice;
		system("cls");

		switch (choice)
		{
		case print:
			if (books == nullptr)
				cout << "Данные не внесены\n";
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

