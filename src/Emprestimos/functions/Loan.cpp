#include <iostream>
#include <thread>
#include <chrono>
#include <stdlib.h>
#include "Loan.h"
#include "../../Biblioteca/Biblioteca.h"

using namespace std;

void printLoan(const Loan& loan) {
  cout << "\x1B[2J\x1B[H";
  cout << "Você fez o empréstimo desse Livro: " << endl;
  cout << "-------------------------" << endl;
  cout << "Título: " << loan.title << endl;
  cout << "Autor: " << loan.author << endl;
  cout << "Dia do Empréstimo: " << loan.loanDay << endl;
  cout << "Dia da Devolução: " << loan.returnDay << endl;
  cout << "-------------------------" << endl;
  this_thread::sleep_for(chrono::seconds(3));
  cout << "\x1B[2J\x1B[H";
}

void registerLoan() {
  Loan newLoan;
  int calc;

  cin.ignore();
  cout << "EMPRESTANDO LIVRO !!!" << endl;
  cout << "-------------------------" << endl;
  cout << "Digite o título: ";
  getline(cin, newLoan.title);

  cout << "Digite o autor: ";
  getline(cin, newLoan.author);

  cout << "Digite o dia do seu Empréstimo: ";
  cin >> newLoan.loanDay;

  calc = newLoan.loanDay + 5;
  newLoan.returnDay = calc;
  cout << "-------------------------" << endl;

  Library::loans.push_back(newLoan);

  printLoan(newLoan);
}

void listLoans() {
  if (Library::loans.empty()) {
    cout << "Não há empréstimos cadastrados." << endl;
  }
  else {
    cout << "EMPRÉSTIMOS CADASTRADOS:" << endl;
    for (const Loan& loan : Library::loans) {
      cout << "-------------------------" << endl;
      cout << "Título: " << loan.title << endl;
      cout << "Autor: " << loan.author << endl;
      cout << "Dia do empréstimo: " << loan.loanDay << endl;
      cout << "Dia da devolução: " << loan.returnDay << endl;
    }
    cout << "-------------------------" << endl;
  }
}
