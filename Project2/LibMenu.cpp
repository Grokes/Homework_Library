#include "LibMenu.h"

using namespace std;

void Menu_Find(Book* books, int size)
{
	if (books == nullptr)
	{
		cout << "������ �� �������\n";
		system("pause");
		return;
	}
	int choice{};
	string arg_find{};
	vector<int> bookIndArr{};

	cout << "1. ����� �� ��������\n"
		<< "2. ����� �� ������\n"
		<< "����: ";
	cin >> choice;
	system("cls");

	switch (choice)
	{
	case 1:
		cout << "������� �������� �����: ";

		cin.ignore();
		getline(cin, arg_find);

		system("cls");

		bookIndArr = FindBook(books, arg_find, title, size);

		if (bookIndArr.size() != 0)
			PrintBook(books + bookIndArr[0]);
		else
			cout << "����� �� �������\n";
		break;
	case 2:
		cout << "������� ��� ������: ";

		cin.ignore();
		getline(cin, arg_find);

		system("cls");

		bookIndArr = FindBook(books, arg_find, author, size);

		if (bookIndArr.size() != 0)
			for (int i{}; i < bookIndArr.size(); i++)
				PrintBook(books + bookIndArr[i]);
		else
			cout << "����� �� �������\n";
		break;
	default:
		break;
	}
	system("pause");
}

void Menu_Sort(Book* books, int size)
{
	if (books == nullptr)
	{
		cout << "������ �� �������\n";
		system("pause");
		return;
	}
	int choice{};

	cout << "1. ���������� �� ��������\n"
		<< "2. ���������� �� ������\n"
		<< "3. ���������� �� ������������\n"
		<< "����: ";
	cin >> choice;
	system("cls");

	switch (choice)
	{
	case 1:
		SortedBooks(books, title, size);
		break;
	case 2:
		SortedBooks(books, author, size);
		break;
	case 3:
		SortedBooks(books, pubHouse, size);
		break;
	default:
		break;
	}
}

void Menu_Edit(Book* books, int size)
{
	if (books == nullptr)
	{
		cout << "������ �� �������\n";
		system("pause");
		return;
	}
	int choice{};
	string new_data{};
	int book_ind{};

	do
	{
		system("cls");
		cout << "������� ������ �����: ";
		cin >> book_ind;
		system("cls");
	} while (book_ind < 0 || book_ind >= size);

	cout << "1. �������� ��������\n"
		<< "2. �������� ������\n"
		<< "3. �������� ����\n"
		<< "4. �������� ������������\n"
		<< "����: ";
	cin >> choice;

	system("cls");
	cout << "������� ����� ������: ";
	cin.ignore();
	getline(cin, new_data);
	system("cls");

	switch (choice)
	{
	case 1:
		EditBook(books + book_ind, new_data, title);
		break;
	case 2:
		EditBook(books + book_ind, new_data, author);
		break;
	case 3:
		EditBook(books + book_ind, new_data, genre);
		break;
	case 4:
		EditBook(books + book_ind, new_data, pubHouse);
		break;
	default:
		break;
	}
}

void Menu_SaveLoad(Book*& books, int& size, bool (**func)(Book*&, int&, const char*))
{
	int choice{};
	string path{};
	cout << "������ �����\n"
			"1. .txt\n"
			"2. .bin\n"
			"����: ";
	cin >> choice;
	system("cls");

	cout << "������� ����: ";
	cin.ignore();
	getline(cin, path);
	system("cls");

	switch (choice)
	{
	case 1:
		if (!func[0](books, size, path.c_str()))
			cout << "�������� �������\n";
		else
			cout << "�������\n";
		break;
	case 2:
		if (!func[1](books, size, path.c_str()))
			cout << "�������� �������\n";
		else
			cout << "�������\n";
		break;
	default:
		break;
	}
	

	system("pause");
}

void Menu_Read(bool (**func)(Book*&, int&, const char*))
{
	Book* books_temp{};
	int size_temp{};
	int ind{};
	int choice{};
	string path{};

	cout << "������ �����\n"
		"1. .txt\n"
		"2. .bin\n"
		"����: ";
	cin >> choice;
	system("cls");

	cout << "������� ����: ";
	cin.ignore();
	getline(cin, path);
	system("cls");


	switch (choice)
	{
	case 1:
		if (!func[0](books_temp, size_temp, path.c_str()))
		{
			cout << "������� ������ ������: ";
			cin >> ind;
			if (ind < size_temp)
				PrintBook(&books_temp[ind]);
			else
				cout << "������ �� �������\n";
		}
		else
			cout << "�� ������� ������� ����\n";
		break;
	case 2:
		if (!func[1](books_temp, size_temp, path.c_str()))
		{
			cout << "������� ������ ������: ";
			cin >> ind;
			if (ind < size_temp)
				PrintBook(&books_temp[ind]);
			else
				cout << "������ �� �������\n";
		}
		else
			cout << "�� ������� ������� ����\n";
		break;
	default:
		break;
	}

	system("pause");
}