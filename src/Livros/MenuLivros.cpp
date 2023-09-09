#include "functions/Book.h"
#include "../Utilities/Includes.h"
#include "../Biblioteca/Biblioteca.h"

using namespace std;

void bookMenu() {

  int option;

  do {
    cout << "MENU LIVROS" << endl;
    cout << "\n1. Cadastrar Livro\n";
    cout << "2. Listar Livros Cadastrados\n";
    cout << "3. Pesquisar Livros Cadastrados\n";
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

    switch (option) {
    case 1: registerBook();
      break;
    case 2: listBooks();
      break;
    case 3: searchBook();
      break;
    }
  } while (option != 0);
}
