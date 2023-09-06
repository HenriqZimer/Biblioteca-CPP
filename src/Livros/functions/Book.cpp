#include <iostream>
#include <thread>
#include <chrono>
#include <stdlib.h>
#include "Book.h"
#include "../../Utilities/Includes.h"
#include "../../Biblioteca/Biblioteca.h"

using namespace std;

void registerBook() {
  Book newBook;

  cin.ignore();
  cout << "CADASTRANDO LIVRO !!!" << endl;
  cout << "-------------------------" << endl;
  cout << "Digite o título: ";
  getline(cin, newBook.title);

  cout << "Digite o autor: ";
  getline(cin, newBook.author);

  cout << "Digite o ano de Publicação: ";
  cin >> newBook.publicationYear;

  cout << "Digite o número de cópias: ";
  cin >> newBook.copyNumbers;
  cout << "-------------------------" << endl;

  Library::books.push_back(newBook);

  printBook(newBook);
}

void printBook(const Book& book) {
  clear();
  cout << "Você cadastrou esse Livro: " << endl;
  cout << "-------------------------" << endl;
  cout << "Título: " << book.title << endl;
  cout << "Autor: " << book.author << endl;
  cout << "Ano de Publicação: " << book.publicationYear << endl;
  cout << "Número de Cópias: " << book.copyNumbers << endl;
  cout << "-------------------------" << endl;
  pauseAndClear();
}

void listBooks() {
  clear();
  if (Library::books.empty()) {
    cout << "Não há livros cadastrados." << endl;
  }
  else {
    cout << "LIVROS CADASTRADOS" << endl;
    for (const Book& book : Library::books) {
      cout << "-------------------------" << endl;
      cout << "Título: " << book.title << endl;
      cout << "Autor: " << book.author << endl;
      cout << "Ano de Publicação: " << book.publicationYear << endl;
      cout << "Número de Cópias: " << book.copyNumbers << endl;
    }
    cout << "-------------------------" << endl;
  }
  pauseAndClear();
}
