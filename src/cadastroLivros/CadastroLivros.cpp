#include "functions/Book.h"
#include <iostream>
#include <locale.h>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

void menuCadastroLivros() {
  setlocale(LC_ALL, "portuguese");
  vector<Book> books;

  int option;

  do {
    cout << "MENU CADASTRO DE LIVROS" << endl;
    cout << "\n1. Registrar Livro\n";
    cout << "2. Listar Livros\n";
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


// Comando Build cd d: && cd REPOSITÓRIO/Estudos/C++/Biblioteca-CPP/src/cadastroLivros/ && g++ main.cpp Book.cpp -o cadastroLivros.exe