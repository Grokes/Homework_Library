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
		cout << "����� ���������� �����������" << endl
			<< "1. ������� ������ ����\n"
			<< "2. �����\n"
			<< "3. ���������� ����\n"
			<< "4. ������ ��������� � ������\n"
			<< "5. �����\n"
			<< "����: ";
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

