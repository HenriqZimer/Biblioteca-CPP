#include <iostream>
#include <locale.h>
#include <vector>
#include <thread>
#include <chrono>
#include "functions/Book.h"

using namespace std;

void bookMenu() {
  setlocale(LC_ALL, "portuguese");
  vector<Book> books;

  int option;

  do {
    cout << "MENU LIVROS" << endl;
    cout << "\n1. Cadastrar Livro\n";
    cout << "2. Listar Livros Cadastrados\n";
    cout << "3. Sair\n";
    cout << "Escolha uma Opção: ";
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
}
