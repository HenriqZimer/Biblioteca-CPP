#include "Loan.h"
#include <iostream>
#include <locale>
#include <vector>
#include <string>
#include <stdlib.h>
#include <thread>
#include <chrono>

using namespace std;

int main() {
  setlocale(LC_ALL, "portuguese");
  vector<Loan> loans;

  int option;
  do {
    cout << "MENU REGISTRO DE EMPRÉSTIMOS DE LIVROS" << endl;
    cout << "\n1. Cadastrar Livro\n";
    cout << "2. Listar Empréstimos\n";
    cout << "3. Sair\n";
    cout << "Escolha uma opção: ";
    cin >> option;
    cout << "\x1B[2J\x1B[H";

    if (option == 1) {
      registerLoan(loans);
    }
    else if (option == 2) {
      listLoans(loans);
      this_thread::sleep_for(chrono::seconds(5));
      cout << "\x1B[2J\x1B[H";
    }
  } while (option != 3);


  return 0;
}

// Comando Build g++ main.cpp Loan.cpp -o output.exe, lembre de estar no diretorio do main.cpp no terminal
