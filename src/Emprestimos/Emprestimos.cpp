#include <iostream>
#include <locale.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include "functions/Loan.h"
#include "../Biblioteca/Biblioteca.h"

using namespace std;

void loanMenu() {
  setlocale(LC_ALL, "portuguese");

  int option;

  do {
    cout << "MENU EMPRÉSTIMOS DE LIVROS" << endl;
    cout << "\n1. Empréstimo Livro\n";
    cout << "2. Listar Empréstimos\n";
    cout << "3. Sair\n";
    cout << "-------------------------" << endl;
    cout << "Número de empréstimos registrados: " << Library::loans.size() << endl;
    if (!Library::loans.empty()) {
      cout << "Último empréstimo registrado: " << Library::loans.back().title << endl;
    }
    cout << "-------------------------" << endl;
    cout << "Escolha uma opção: ";
    cin >> option;
    cin.ignore();
    cout << "\x1B[2J\x1B[H";

    if (option == 1) {
      registerLoan();
    }
    else if (option == 2) {
      listLoans();
      this_thread::sleep_for(chrono::seconds(5));
      cout << "\x1B[2J\x1B[H";
    }
  } while (option != 3);
}

