#include <iostream>
#include <thread>
#include <chrono>
#include <stdlib.h>
#include "Loan.h"
#include "../../Utilities/Includes.h"
#include "../../Biblioteca/Biblioteca.h"

using namespace std;

// Funções Reutilizadas ------------------------------
bool checkExistence(bool condition, const string& errorMessage) {
  if (!condition) {
    cout << "Erro: " << errorMessage << endl;
    pauseAndClear();
    return false;
  }
  return true;
}

User* findUser(const string& userName) {
  for (User& user : Library::users) {
    if (user.name == userName) {
      return &user;
    }
  }
  return nullptr;
}

Book* findBook(const string& bookTitle) {
  for (Book& book : Library::books) {
    if (book.title == bookTitle) {
      return &book;
    }
  }
  return nullptr;
}

void printSingleLoan(const Loan& loan) {
  printDivider();
  cout << "Usuário: " << loan.user << endl;
  cout << "Título: " << loan.title << endl;
  cout << "Autor: " << loan.author << endl;
  cout << "Dia do Empréstimo: " << loan.loanDay << endl;
  cout << "Dia da Devolução: " << loan.returnDay << endl;
  printDivider();
}

// ---------------------------------------------------

// Função de Cadastro de Emprestimo ------------------
void registerLoan() {
  Loan newLoan;
  int loanTime;

  cin.ignore();
  cout << "EMPRESTANDO LIVRO !!!" << endl;
  printDivider();

  cout << "Digite o nome do Usuario: ";
  getline(cin, newLoan.user);

  User* user = findUser(newLoan.user);
  if (!checkExistence(user, "Usuário não encontrado no sistema.")) return;


  cout << "Digite o título: ";
  getline(cin, newLoan.title);

  Book* book = findBook(newLoan.title);
  if (!checkExistence(book, "Livro não encontrado no sistema.")) return;

  cout << "Digite o autor: ";
  getline(cin, newLoan.author);

  if (!checkExistence(Library::authorExists(newLoan.author), "Autor não encontrado no sistema.")) return;

  cout << "Digite o dia do seu Empréstimo: ";
  cin >> newLoan.loanDay;

  cout << "Digite quantidade de dia(s) para seu  Empréstimo: ";
  cin >> loanTime;

  newLoan.returnDay = newLoan.loanDay + loanTime;
  printDivider();

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
// ---------------------------------------------------

// Função de Imprimir Emprestimo depois do Cadastro ---
void printLoan(const Loan& loan) {
  clear();
  cout << "Você fez o empréstimo desse Livro: " << endl;
  printSingleLoan(loan);
  pauseAndClear();
}
// ---------------------------------------------------

// Função de Lista os Emprestimos --------------------
void listLoans() {
  clear();
  if (Library::loans.empty()) {
    cout << "Não há empréstimos cadastrados." << endl;
  }
  else {
    cout << "EMPRÉSTIMOS CADASTRADOS:" << endl;
    for (const Loan& loan : Library::loans) {
      printSingleLoan(loan);
    }
  }
  pauseAndClear();
}
// ---------------------------------------------------

// Função de Devolução dos Emprestimos ---------------
void bookReturn() {
  string userName, bookTitle, bookAuthor, verificationNumber;

  cin.ignore();
  cout << "DEVOLUÇÃO DE LIVRO" << endl;
  printDivider();
  cout << "Digite o numero de verificação: ";
  getline(cin, userName);

  cout << "Digite o nome do Usuario: ";
  getline(cin, userName);

  if (!Library::userExists(userName)) {
    cout << "Erro: Usuário não encontrado no sistema." << endl;
    pauseAndClear();
    return;
  }

  cout << "Digite o título do livro sendo devolvido: ";
  getline(cin, bookTitle);

  if (!Library::bookExists(bookTitle)) {
    cout << "Erro: Livro não encontrado no sistema." << endl;
    pauseAndClear();
    return;
  }
  if (!Library::authorExists(bookAuthor)) {
    cout << "Erro: Autor não encontrado no sistema." << endl;
    pauseAndClear();
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
      pauseAndClear();
      return;
    }
  }

  cout << "Erro: Empréstimo não encontrado." << endl;
  pauseAndClear();
}
// ---------------------------------------------------