#include <iostream>
#include <locale.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include "functions/Book.h"
#include "../Utilities/Includes.h"
#include "../Biblioteca/Biblioteca.h"

using namespace std;

void bookMenu() {
  setlocale(LC_ALL, "portuguese");

  int option;

  do {
    cout << "MENU LIVROS" << endl;
    cout << "\n1. Cadastrar Livro\n";
    cout << "2. Listar Livros Cadastrados\n";
    cout << "0. Sair\n";
    cout << "-------------------------" << endl;
    cout << "Quantidade de cadastro de livros: " << Library::books.size() << endl;
    if (!Library::books.empty()) {
      cout << "Último titúlo cadastrado: " << Library::books.back().title << endl;
    }
    cout << "-------------------------" << endl;
    cout << "Escolha uma Opção: ";
    cin >> option;
    clear();

    if (option == 1) {
      registerBook();
    }
    else if (option == 2) {
      listBooks();
    }
  } while (option != 0);
}
