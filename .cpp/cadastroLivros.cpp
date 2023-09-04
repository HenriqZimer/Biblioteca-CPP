#include <iostream>
#include <locale>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <stdlib.h>

using namespace std;

struct Book {
  string title;
  string author;
  int publicationYear;
  int copyNumbers;
};

void printBook(const Book& book) {
  cout << "\x1B[2J\x1B[H";
  cout << "Voc� cadastrou esse Livro: " << endl;
  cout << "-------------------------" << endl;
  cout << "T�tulo: " << book.title << endl;
  cout << "Autor: " << book.author << endl;
  cout << "Ano de Publica��o: " << book.publicationYear << endl;
  cout << "N�mero de C�pias: " << book.copyNumbers << endl;
  cout << "-------------------------" << endl;
  this_thread::sleep_for(chrono::seconds(3));
  cout << "\x1B[2J\x1B[H";
}

void registerBook(vector<Book>& books) {
  Book newBook;

  cin.ignore();
  cout << "CADASTRANDO LIVRO !!!" << endl;
  cout << "-------------------------" << endl;
  cout << "Digite o t�tulo: ";
  getline(cin, newBook.title);

  cout << "Digite o autor: ";
  getline(cin, newBook.author);

  cout << "Digite o ano de Publica��o: ";
  cin >> newBook.publicationYear;

  cout << "Digite o numero de copias: ";
  cin >> newBook.copyNumbers;
  cout << "-------------------------" << endl;

  books.push_back(newBook);

  printBook(newBook);
}

void listBooks(const vector<Book>& books) {
  if (books.empty()) {
    cout << "N�o h� livros cadastrados." << endl;
  }
  else {
    cout << "LIVROS CADASTRADOS" << endl;
    for (const Book& book : books) {
      cout << "-------------------------" << endl;
      cout << "T�tulo: " << book.title << endl;
      cout << "Autor: " << book.author << endl;
      cout << "Ano de Publica��o: " << book.publicationYear << endl;
      cout << "N�mero de C�pias: " << book.copyNumbers << endl;
    }
    cout << "-------------------------" << endl;
  }
}

int main() {
  setlocale(LC_ALL, "portuguese");
  vector<Book> books;

  int option;
  do {
    cout << "MENU CADASTRO DE LIVROS" << endl;
    cout << "\n1. Registrar Livro\n";
    cout << "2. Listar Livros\n";
    cout << "3. Sair\n";
    cout << "Escolha uma op��o: ";
    cin >> option;
    cout << "\x1B[2J\x1B[H";

    if (option == 1) {
      registerBook(books);
    }
    else if (option == 2) {
      listBooks(books);
      this_thread::sleep_for(chrono::seconds(5));
      cout << "\x1B[2J\x1B[H";
    }
  } while (option != 3);


  return 0;
}
