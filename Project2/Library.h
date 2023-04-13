#pragma once
#include <string>
#include <vector>
using namespace std;

enum BookParam{ title, author, genre, pubHouse };

struct Book
{
	string title;
	string author;
	string genre;
	string pubHouse;
};

void GenArrTest(Book* books);
void PrintAllBooks(Book* books, int size);
void PrintBook(Book* book);
int GetMaxStrSize(Book* book);
void Frame(Book* book);
void SortedBooksLtr(Book* books, int arg_field, int size, int ltrPos = 0);
void SortedBooks(Book* books, int arg_field, int size, int ltrPos = 0);
void EditBook(Book* book, string arg_edit, int arg_field);
vector<int> FindBook(Book* books, string arg_find, int arg_field, int size);