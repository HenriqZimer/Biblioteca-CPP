#include <iostream>
#include <thread>
#include <chrono>
#include <stdlib.h>
#include "Book.h"
#include "../../Biblioteca/Biblioteca.h"

using namespace std;

void printBook(const Book& book) {
  cout << "\x1B[2J\x1B[H";
  cout << "Você cadastrou esse Livro: " << endl;
  cout << "-------------------------" << endl;
  cout << "Título: " << book.title << endl;
  cout << "Autor: " << book.author << endl;
  cout << "Ano de Publicação: " << book.publicationYear << endl;
  cout << "Número de Cópias: " << book.copyNumbers << endl;
  cout << "-------------------------" << endl;
  this_thread::sleep_for(chrono::seconds(3));
  cout << "\x1B[2J\x1B[H";
}

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

void listBooks() {
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
}
