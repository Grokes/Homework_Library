#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>

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
bool SaveBooks(Book*& books, int& size, const char* path = "C:\\TestFolder\\out.txt");
bool LoadBooks(Book*& books, int& size, const char* path = "C:\\TestFolder\\out.txt");
bool SaveBooksBin(Book*& books, int& size, const char* path = "C:\\TestFolder\\outbin.txt");
bool LoadBooksBin(Book*& books, int& size, const char* path = "C:\\TestFolder\\outbin.txt");
void Read(unsigned int ind, const char* path = "C:\\TestFolder\\out.txt");