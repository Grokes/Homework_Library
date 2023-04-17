#include "LibMenu.h"

using namespace std;

void Menu_Find(Book* books, int size)
{
	if (books == nullptr)
	{
		cout << "Данные не внесены\n";
		system("pause");
		return;
	}
	int choice{};
	string arg_find{};
	vector<int> bookIndArr{};

	cout << "1. Поиск по названию\n"
		<< "2. Поиск по автору\n"
		<< "Ввод: ";
	cin >> choice;
	system("cls");

	switch (choice)
	{
	case 1:
		cout << "Введите название книги: ";

		cin.ignore();
		getline(cin, arg_find);

		system("cls");

		bookIndArr = FindBook(books, arg_find, title, size);

		if (bookIndArr.size() != 0)
			PrintBook(books + bookIndArr[0]);
		else
			cout << "Книга не найдена\n";
		break;
	case 2:
		cout << "Введите имя автора: ";

		cin.ignore();
		getline(cin, arg_find);

		system("cls");

		bookIndArr = FindBook(books, arg_find, author, size);

		if (bookIndArr.size() != 0)
			for (int i{}; i < bookIndArr.size(); i++)
				PrintBook(books + bookIndArr[i]);
		else
			cout << "Книга не найдена\n";
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
		cout << "Данные не внесены\n";
		system("pause");
		return;
	}
	int choice{};

	cout << "1. Сортировка по названию\n"
		<< "2. Сортировка по автору\n"
		<< "3. Сортировка по издательству\n"
		<< "Ввод: ";
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
		cout << "Данные не внесены\n";
		system("pause");
		return;
	}
	int choice{};
	string new_data{};
	int book_ind{};

	do
	{
		system("cls");
		cout << "Введите индекс книги: ";
		cin >> book_ind;
		system("cls");
	} while (book_ind < 0 || book_ind >= size);

	cout << "1. Изменить название\n"
		<< "2. Изменить автора\n"
		<< "3. Изменить жанр\n"
		<< "4. Изменить издательство\n"
		<< "Ввод: ";
	cin >> choice;

	system("cls");
	cout << "Введите новые данные: ";
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
	cout << "Формат файла\n"
			"1. .txt\n"
			"2. .bin\n"
			"Ввод: ";
	cin >> choice;
	system("cls");

	cout << "Введите путь: ";
	cin.ignore();
	getline(cin, path);
	system("cls");

	switch (choice)
	{
	case 1:
		if (!func[0](books, size, path.c_str()))
			cout << "Операция успешна\n";
		else
			cout << "Неудача\n";
		break;
	case 2:
		if (!func[1](books, size, path.c_str()))
			cout << "Операция успешна\n";
		else
			cout << "Неудача\n";
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

	cout << "Формат файла\n"
		"1. .txt\n"
		"2. .bin\n"
		"Ввод: ";
	cin >> choice;
	system("cls");

	cout << "Введите путь: ";
	cin.ignore();
	getline(cin, path);
	system("cls");


	switch (choice)
	{
	case 1:
		if (!func[0](books_temp, size_temp, path.c_str()))
		{
			cout << "Введите индекс записи: ";
			cin >> ind;
			if (ind < size_temp)
				PrintBook(&books_temp[ind]);
			else
				cout << "Запись не найдена\n";
		}
		else
			cout << "Не удалось открыть файл\n";
		break;
	case 2:
		if (!func[1](books_temp, size_temp, path.c_str()))
		{
			cout << "Введите индекс записи: ";
			cin >> ind;
			if (ind < size_temp)
				PrintBook(&books_temp[ind]);
			else
				cout << "Запись не найдена\n";
		}
		else
			cout << "Не удалось открыть файл\n";
		break;
	default:
		break;
	}

	system("pause");
}