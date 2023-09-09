#include "functions/Loan.h"
#include "../Utilities/Includes.h"
#include "../Biblioteca/Biblioteca.h"

using namespace std;

void loanMenu() {

  int option;

  do {
    cout << "MENU EMPRÉSTIMOS DE LIVROS" << endl;
    printDivider();
    cout << "\n1. Empréstimo Livro\n";
    cout << "2. Devolução de livro\n";
    cout << "3. Listar Empréstimos\n";
    cout << "0. Sair\n";
    printDivider();
    cout << "Quantidade de registro de empréstimos: " << Library::loans.size() << endl;
    if (!Library::loans.empty()) {
      cout << "Último empréstimo registrado: " << Library::loans.back().title << endl;
    }
    printDivider();
    cout << "Escolha uma opção: ";
    cin >> option;
    cin.ignore();
    clear();

    switch (option) {
    case 1:
      registerLoan();
      break;
    case 2:
      bookReturn();
      break;
    case 3:
      listLoans();
      break;
    case 4:
      break;
    default:
      invalidOption();
      break;
    }
  } while (option != 4);
}
