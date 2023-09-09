#include <iostream>
#include <locale.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include "functions/Loan.h"
#include "../Utilities/Includes.h"
#include "../Biblioteca/Biblioteca.h"

using namespace std;

void loanMenu() {
  setlocale(LC_ALL, "portuguese");

  int option;

  do {
    cout << "MENU EMPRÉSTIMOS DE LIVROS" << endl;
    cout << "\n1. Empréstimo Livro\n";
    cout << "2. Devolução de livro\n";
    cout << "3. Listar Empréstimos\n";
    cout << "0. Sair\n";
    cout << "-------------------------" << endl;
    cout << "Quantidade de registro de empréstimos: " << Library::loans.size() << endl;
    if (!Library::loans.empty()) {
      cout << "Último empréstimo registrado: " << Library::loans.back().title << endl;
    }
    cout << "-------------------------" << endl;
    cout << "Escolha uma opção: ";
    cin >> option;
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
    }
  } while (option != 0);
}
