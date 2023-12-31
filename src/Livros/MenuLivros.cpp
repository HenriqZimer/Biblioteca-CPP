#include "functions/Book.h"
#include "../Utilities/Includes.h"
#include "../Biblioteca/Biblioteca.h"

using namespace std;

void bookMenu() {
  int option;

  do {
    cout << "MENU LIVROS" << endl;
    printDivider();
    cout << "1. Cadastrar Livro\n";
    cout << "2. Listar Livros Cadastrados\n";
    cout << "3. Pesquisar Livros Cadastrados\n";
    cout << "4. Sair\n";
    printDivider();
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
    case 4:
      break;
    default:
      invalidOption();
      break;
    }
  } while (option != 4);
}
