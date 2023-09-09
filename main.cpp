#include "src/Utilities/Includes.h"
#include "src/Livros/MenuLivros.h"
#include "src/Usuarios/MenuUsuarios.h"
#include "src/Emprestimos/MenuEmprestimos.h"
#include "src/Biblioteca/Biblioteca.h"

using namespace std;

int main() {
  setlocale(LC_ALL, "portuguese");

  int option = 0;
  clear();
  do {
    cout << "BIBLIOTECA VH" << endl;
    printDivider();
    cout << "MENU PRINCIPAL" << endl;
    cout << "\n1. Menu Livros\n";
    cout << "2. Menu Usuários\n";
    cout << "3. Menu Empréstimos\n";
    cout << "6. Estatísticas Geral\n";
    cout << "0. Sair\n";

    cout << "Escolha uma opção: ";
    cin >> option;
    cin.ignore();
    clear();

    switch (option) {
    case 1:
      bookMenu();
      break;
    case 2:
      userMenu();
      break;
    case 3:
      loanMenu();
      break;
    case 4:
      break;
    case 5:
      Library::listBooksMain();
      break;
    case 6:
      break;
    case 10:
      Library::listBooksMain();
      break;
    case 11:
      Library::listUsersMain();
      break;
    case 12:
      Library::listLoansMain();
      break;
    }
  } while (option != 0);
  return 0;
}


