#include <iostream>
#include <locale.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include "functions/Book.h"
#include "../Biblioteca/Biblioteca.h"

using namespace std;

void bookMenu() {
  setlocale(LC_ALL, "portuguese");

  int option;

  do {
    cout << "MENU LIVROS" << endl;
    cout << "\n1. Cadastrar Livro\n";
    cout << "2. Listar Livros Cadastrados\n";
    cout << "3. Sair\n";
    cout << "-------------------------" << endl;
    cout << "Número de livros registrados: " << Library::books.size() << endl;
    if (!Library::books.empty()) {
      cout << "Último titúlo registrado: " << Library::books.back().title << endl;
    }
    cout << "-------------------------" << endl;
    cout << "Escolha uma Opção: ";
    cin >> option;
    cout << "\x1B[2J\x1B[H";

    if (option == 1) {
      registerBook();
    }
    else if (option == 2) {
      listBooks();
      this_thread::sleep_for(chrono::seconds(5));
      cout << "\x1B[2J\x1B[H";
    }
  } while (option != 3);
}
