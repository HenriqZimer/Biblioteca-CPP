#include <iostream>
#include <locale>
#include <thread> 
#include "src/Livros/Livros.h"
#include "src/Usuarios/Usuarios.h"
#include "src/Emprestimos/Emprestimos.h"
#include "src/Biblioteca/Biblioteca.h"

using namespace std;

int main() {
  setlocale(LC_ALL, "portuguese");

  int option = 0;
  cout << "\x1B[2J\x1B[H";
  do {
    cout << "BIBLIOTECA VH" << endl;
    cout << "-------------------------" << endl;
    cout << "MENU PRINCIPAL" << endl;
    cout << "\n1. Menu Livros\n";
    cout << "2. Menu Usuários\n";
    cout << "3. Menu Empréstimos\n";
    // cout << "3. Listar Livros\n";
    // cout << "4. Listar Usuários\n";
    cout << "5. Sair\n";

    cout << "Escolha uma opção: ";
    cin >> option;
    cin.ignore();
    cout << "\x1B[2J\x1B[H";

    switch (option) {
    case 1:
      bookMenu();
      break;
    case 2:
      userMenu();
      break;
    case 3:
      loanMenu();
    case 11:
      Library::listBooksMain();
      break;
    case 10:
      Library::listUsersMain();
      break;
    case 12:
      Library::listLoansMain();
      break;
    }
  } while (option != 5);
  return 0;
}


