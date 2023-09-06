#include <iostream>
#include <thread>
#include <chrono>
#include <stdlib.h>
#include "Loan.h"
#include "../../Utilities/Includes.h"
#include "../../Biblioteca/Biblioteca.h"

using namespace std;

void printLoan(const Loan& loan) {
  clear();
  cout << "Você fez o empréstimo desse Livro: " << endl;
  cout << "-------------------------" << endl;
  cout << "Usuário: " << loan.user << endl;
  cout << "Título: " << loan.title << endl;
  cout << "Autor: " << loan.author << endl;
  cout << "Dia do Empréstimo: " << loan.loanDay << endl;
  cout << "Dia da Devolução: " << loan.returnDay << endl;
  cout << "-------------------------" << endl;
  pauseAndClear();
}

void registerLoan() {
  Loan newLoan;
  int loanTime;

  cin.ignore();
  cout << "EMPRESTANDO LIVRO !!!" << endl;
  cout << "-------------------------" << endl;

  cout << "Digite o nome do Usuario: ";
  getline(cin, newLoan.user);

  if (!Library::userExists(newLoan.user)) {
    cout << "Este usuário não está cadastrado no nosso sistema. Emprestimo cancelado." << endl;
    pauseAndClear();
    return;
  }

  cout << "Digite o título: ";
  getline(cin, newLoan.title);

  if (!Library::bookExists(newLoan.title)) {
    cout << "Este livro não está cadastrado no nosso sistema. Empréstimo cancelado." << endl;
    pauseAndClear();
    return;
  }

  cout << "Digite o autor: ";
  getline(cin, newLoan.author);

  if (!Library::authorExists(newLoan.author)) {
    cout << "Este autor não está cadastrado no nosso sistema. \nEmpréstimo cancelado." << endl;
    pauseAndClear();
    return;
  }

  cout << "Digite o dia do seu Empréstimo: ";
  cin >> newLoan.loanDay;

  cout << "Digite quantidade de dia(s) para seu  Empréstimo: ";
  cin >> loanTime;

  newLoan.returnDay = newLoan.loanDay + loanTime;
  cout << "-------------------------" << endl;

  for (User& user : Library::users) {
    if (user.name == newLoan.user) {
      user.numberLoans++;
      break;
    }
  }
  for (Book& book : Library::books) {
    if (book.author == newLoan.author && book.title == newLoan.title) {
      book.copyNumbers--;
      break;
    }
  }

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
      cout << "Usuário: " << loan.user << endl;
      cout << "Título: " << loan.title << endl;
      cout << "Autor: " << loan.author << endl;
      cout << "Dia do empréstimo: " << loan.loanDay << endl;
      cout << "Dia da devolução: " << loan.returnDay << endl;
    }
    cout << "-------------------------" << endl;
  }
  pauseAndClear();
}

void bookReturn() {
  string userName, bookTitle;

  cin.ignore();
  cout << "DEVOLUÇÃO DE LIVRO" << endl;
  cout << "-------------------------" << endl;
  cout << "Digite o nome do Usuario: ";
  getline(cin, userName);

  cout << "Digite o título do livro sendo devolvido: ";
  getline(cin, bookTitle);

  if (!Library::userExists(userName) || !Library::bookExists(bookTitle)) {
    cout << "Erro: Usuário ou livro não encontrados no sistema." << endl;
    return;
  }

  for (auto i = Library::loans.begin(); i != Library::loans.end(); ++i) {
    if (i->user == userName && i->title == bookTitle) {
      Library::loans.erase(i);

      for (User& user : Library::users) {
        if (user.name == userName) {
          user.numberLoans--;
          break;
        }
      }

      cout << "Devolução registrada com sucesso!" << endl;
      return;
    }
  }

  cout << "Erro: Empréstimo não encontrado." << endl;
  pauseAndClear();
}