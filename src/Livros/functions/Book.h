#ifndef BOOK_H
#define BOOK_H

#include <vector>
#include <string>

using namespace std;

struct Book {
  string title;
  string author;
  int publicationYear;
  int copyNumbers;
};

void printBook(const Book& book);
void registerBook();
void listBooks();
void searchBook();

#endif