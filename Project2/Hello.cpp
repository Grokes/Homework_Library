#include <iostream>
#include <string>
#include <stdlib.h>
#include "Library.h"
#include <Windows.h>
#include "LibMenu.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);

	enum { print = 1, find, sort, edit, _exit };
	int SIZE{ 6 };
	int choice{};

	Book* books = new Book[SIZE]{};
	GenArrTest(books);

	while (true)
	{
		system("cls");
		cout << "Центр управления библиотекой" << endl
			<< "1. Вывести список книг\n"
			<< "2. Поиск\n"
			<< "3. Сортировка книг\n"
			<< "4. Внести изменения в данные\n"
			<< "5. Выход\n"
			<< "Ввод: ";
		cin >> choice;
		system("cls");

		switch (choice)
		{
		case print:
			PrintArr(books, SIZE);
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
		case _exit:
			exit(0);
			break;
		default:
			break;
		}
	}

	return 0;
}

