#include <iostream>
#include "Library.h"

using namespace std;

void PrintAllBooks(Book* books, int size)
{
	for (int i{}; i < size; i++)
	{
		cout << "������ �����: " << i << endl; 
		PrintBook(books + i);
	}
}

void PrintBook(Book* book)
{
	Frame(book);
	cout << "��������: " << "\"" << book->title << "\"" << endl;
	cout << "�����: " << book->author << endl;
	cout << "����: " << book->genre << endl;
	cout << "������������: " << book->pubHouse << endl;
	Frame(book);
	cout << endl;
}

void Frame(Book* book)
{
	int tempSize = GetMaxStrSize(book);

	cout << "------------";
	for (int j{}; j < tempSize; j++)
	{
		cout << "-";
	}
	cout << endl;
}

int GetMaxStrSize(Book* book)
{
	int temp1 = max(book->author.size(), book->title.size());
	int temp2 = max(book->genre.size(), book->pubHouse.size());
	return max(temp1, temp2);
}

void SortedBooksLtr(Book* books, int arg_field, int size, int ltrPos)
{
	char letter{}; // ������� �������
	int i = 0;
	int j = size - 1;

	switch (arg_field)
	{
	case title:
		letter = books[size / 2].title[ltrPos]; // ������� �������
		do
		{
			while (books[i].title[ltrPos] < letter) i++;
			while (books[j].title[ltrPos] > letter) j--;
			if (i <= j)
			{
				swap(books[i], books[j]);
				i++;
				j--;
			}
		} while (i <= j);

		if (j > 0) SortedBooksLtr(books, title, j + 1, ltrPos);
		if (i < size - 1) SortedBooksLtr(books + i, title, size - i, ltrPos);
		break;
	case author:
		letter = books[size / 2].author[ltrPos]; // ������� �������
		do
		{
			while (books[i].author[ltrPos] < letter) i++;
			while (books[j].author[ltrPos] > letter) j--;
			if (i <= j)
			{
				swap(books[i], books[j]);
				i++;
				j--;
			}
		} while (i <= j);

		if (j > 0) SortedBooksLtr(books, author, j + 1, ltrPos);
		if (i < size - 1) SortedBooksLtr(books + i, author, size - i, ltrPos);
		break;
	case pubHouse:
		letter = books[size / 2].pubHouse[ltrPos]; // ������� �������
		do
		{
			while (books[i].pubHouse[ltrPos] < letter) i++;
			while (books[j].pubHouse[ltrPos] > letter) j--;
			if (i <= j)
			{
				swap(books[i], books[j]);
				i++;
				j--;
			}
		} while (i <= j);

		if (j > 0) SortedBooksLtr(books, pubHouse, j + 1, ltrPos);
		if (i < size - 1) SortedBooksLtr(books + i, pubHouse, size - i, ltrPos);
		break;
	default:
		break;
	}
}

void SortedBooks(Book* books, int arg_field, int size, int ltrPos)
{
	switch (arg_field)
	{
	case title:
		SortedBooksLtr(books, title, size, ltrPos);
		for (int i{}, counter_size{}, counter_st{}; i < size - 1; i++)
		{
			if (ltrPos == books[i].title.size())
				return;
			counter_size++;
			if ((books[i].title[ltrPos] != books[i + 1].title[ltrPos]))
			{
				if (counter_size > 1)
				{
					SortedBooks(books + counter_st, title, counter_size, ltrPos + 1);
				}
				counter_size = 0;
				counter_st = i + 1;
			}
			else if (i == size - 2)
			{
				SortedBooks(books + counter_st, title, counter_size + 1, ltrPos + 1);
			}
		}
		break;
	case author:
		SortedBooksLtr(books, author, size, ltrPos);
		for (int i{}, counter_size{}, counter_st{}; i < size - 1; i++)
		{
			if (ltrPos == books[i].author.size())
				return;
			counter_size++;
			if ((books[i].author[ltrPos] != books[i + 1].author[ltrPos]))
			{
				if (counter_size > 1)
				{
					SortedBooks(books + counter_st, author, counter_size, ltrPos + 1);
				}
				counter_size = 0;
				counter_st = i + 1;
			}
			else if (i == size - 2)
			{
				SortedBooks(books + counter_st, author, counter_size + 1, ltrPos + 1);
			}
		}
		break;
	case pubHouse:
		SortedBooksLtr(books, pubHouse, size, ltrPos);
		for (int i{}, counter_size{}, counter_st{}; i < size - 1; i++)
		{
			if (ltrPos == books[i].pubHouse.size())
				return;
			counter_size++;
			if ((books[i].pubHouse[ltrPos] != books[i + 1].pubHouse[ltrPos]))
			{
				if (counter_size > 1)
				{
					SortedBooks(books + counter_st, pubHouse, counter_size, ltrPos + 1);
				}
				counter_size = 0;
				counter_st = i + 1;
			}
			else if (i == size - 2)
			{
				SortedBooks(books + counter_st, pubHouse, counter_size + 1, ltrPos + 1);
			}
		}
		break;
	default:
		break;
	}
}

void EditBook(Book* book, string arg_edit, int arg_field)
{
	switch (arg_field)
	{
	case title:
		book->title = arg_edit;
		break;
	case author:
		book->author = arg_edit;
		break;
	case pubHouse:
		book->pubHouse = arg_edit;
		break;
	case genre:
		book->genre = arg_edit;
		break;
	default:
		break;
	}
}

void GenArrTest(Book* books)
{
	books[0].title = "��� ��������";
	books[0].author = "����";
	books[0].pubHouse = "�����������";
	books[0].genre = "�����";

	books[1].title = "���� ������";
	books[1].author = "�����";
	books[1].pubHouse = "�����������";
	books[1].genre = "�������";

	books[2].title = "��� ��� ���� � �������������";
	books[2].author = "����������";
	books[2].pubHouse = "���������";
	books[2].genre = "����";

	books[3].title = "��� ��������";
	books[3].author = "����";
	books[3].pubHouse = "�����������";
	books[3].genre = "�����";

	books[4].title = "��� ��������";
	books[4].author = "����";
	books[4].pubHouse = "�����������";
	books[4].genre = "�����";

	books[5].title = "��� ��������";
	books[5].author = "����";
	books[5].pubHouse = "�����������";
	books[5].genre = "�����";
}

vector<int> FindBook(Book* books, string arg_find, int arg_field, int size)
{
	vector<int> result{};
	switch (arg_field)
	{
	case title:
		for (int i{}; i < size; i++)
		{
			if (arg_find == books[i].title)
			{
				result.push_back(i);
				return result;
			}
		}
		break;
	case author:
		for (int i{}; i < size; i++)
		{
			if (arg_find == books[i].author)
				result.push_back(i);
		}
		break;
	default:
		break;
	}

	return result;
}