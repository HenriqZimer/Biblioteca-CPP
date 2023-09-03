#include <iostream>
#include <locale>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <stdlib.h>

using namespace std;

struct Loan {
  string title;
  string author;
  int loanDay;
  int returnDay;
};

void printLoan(const Loan& loan) {
  cout << "\x1B[2J\x1B[H";
  cout << "Você fez o empréstimo desse Livro: " << endl;
  cout << "-------------------------" << endl;
  cout << "Título: " << loan.title << endl;
  cout << "Autor: " << loan.author << endl;
  cout << "Dia do Emprestimo: " << loan.loanDay << endl;
  cout << "Dia da Devolução: " << loan.returnDay << endl;
  cout << "-------------------------" << endl;
  this_thread::sleep_for(chrono::seconds(3));
  cout << "\x1B[2J\x1B[H";
}

void registerLoan(vector<Loan>& loans) {
  Loan newLoan;
  int calc;

  cin.ignore();
  cout << "EMPRESTANDO LIVRO !!!" << endl;
  cout << "-------------------------" << endl;
  cout << "Digite o t�tulo: ";
  getline(cin, newLoan.title);

  cout << "Digite o autor: ";
  getline(cin, newLoan.author);

  cout << "Digite o dia do seu Emprestimo: ";
  cin >> newLoan.loanDay;

  calc = newLoan.loanDay + 5;
  newLoan.returnDay = calc;

  cout << "-------------------------" << endl;

  loans.push_back(newLoan);

  printLoan(newLoan);

}

void listLoans(const vector<Loan>& loans) {
  if (loans.empty()) {
    cout << "N�o h� livros cadastrados." << endl;
  }
  else {
    cout << "EMPR�STIMOS CADASTRADOS" << endl;
    for (const Loan& loan : loans) {
      cout << "-------------------------" << endl;
      cout << "T�tulo: " << loan.title << endl;
      cout << "Autor: " << loan.author << endl;
      cout << "Dia do empr�stimo: " << loan.loanDay << endl;
      cout << "Dia da devolucao: " << loan.returnDay << endl;
    }
    cout << "-------------------------" << endl;
  }
}

int main() {
  setlocale(LC_ALL, "portuguese");
  vector<Loan> loans;

  int option;
  do {
    cout << "MENU REGISTRO DE EMPR�STIMOS DE LIVROS" << endl;
    cout << "\n1. Registrar Livro\n";
    cout << "2. Listar Empr�stimos\n";
    cout << "3. Sair\n";
    cout << "Escolha uma op��o: ";
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
