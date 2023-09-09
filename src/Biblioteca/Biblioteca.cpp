#include <iostream>
#include <thread>
#include <chrono>
#include "../Utilities/Includes.h"
#include "Biblioteca.h"

using namespace std;

vector<Book> Library::books;
vector<User> Library::users;
vector<Loan> Library::loans;

void Library::listBooksMain() {
  if (books.empty()) {
    cout << "Não há livros cadastrados." << endl;
  }
  else {
    cout << "LIVROS CADASTRADOS" << endl;
    for (const Book& book : books) {
      cout << "-------------------------" << endl;
      cout << "Título: " << book.title << endl;
      cout << "Autor: " << book.author << endl;
      cout << "Ano de Publicação: " << book.publicationYear << endl;
      cout << "Número de Cópias: " << book.copyNumbers << endl;
    }
    cout << "-------------------------" << endl;
  }
  pauseAndClear();
}

void Library::listUsersMain() {
  if (users.empty()) {
    cout << "Não há usuários cadastrados." << endl;
  }
  else {
    cout << "USUÁRIOS CADASTRADOS:" << endl;
    for (const User& user : users) {
      cout << "-------------------------" << endl;
      cout << "Nome: " << user.name << endl;
      cout << "Número de verificação: " << user.verificationNumber << endl;
      cout << "Quantidade de livros emprestados: " << user.numberLoans << endl;
    }
    cout << "-------------------------" << endl;
  }
  pauseAndClear();
}

void Library::listLoansMain() {
  if (loans.empty()) {
    cout << "Não há empréstimos cadastrados." << endl;
  }
  else {
    cout << "EMPRÉSTIMOS CADASTRADOS: " << endl;
    for (const Loan& loan : loans) {
      cout << "-------------------------" << endl;
      cout << "Usuário: " << loan.user << endl;
      cout << "Título: " << loan.title << endl;
      cout << "Autor: " << loan.author << endl;
      cout << "Dia do Empréstimo: " << loan.loanDay << endl;
      cout << "Dia da Devolução: " << loan.returnDay << endl;
    }
    cout << "-------------------------" << endl;
    pauseAndClear(3);
  }
}

bool Library::userExists(const string& name) {
  for (const User& user : users) {
    if (user.name == name) {
      return true;
    }
  }
  return false;
}

// bool Library::numberExists(const string& verificationNumber) {
//   for (const User& user : users) {
//     if (user.verificationNumber == verificationNumber) {
//       return true;
//     }
//   }
//   return false;
// }

bool Library::bookExists(const string& title) {
  for (const Book& book : books) {
    if (book.title == title) {
      return true;
    }
  }
  return false;
}

bool Library::authorExists(const string& author) {
  for (const Book& book : books) {
    if (book.author == author) {
      return true;
    }
  }
  return false;
}