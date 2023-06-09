#pragma once
#include <iostream>
#include "Library.h"

void Menu_Find(Book* books, int size);
void Menu_Sort(Book* books, int size);
void Menu_Edit(Book* books, int size);
void Menu_SaveLoad(Book*& books, int& size, bool (**func)(Book*&, int&, const char*));
void Menu_Read(bool (**func)(Book*&, int&, const char*));