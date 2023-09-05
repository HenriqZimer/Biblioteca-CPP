#include <iostream>
#include <thread>
#include <chrono>
#include "Biblioteca.h"

using namespace std;

vector<Book> Library::books;
vector<User> Library::users;
vector<Loan> Library::loans;

void Library::listBooksMain() {
  if (books.empty()) {
    cout << "Não há livros cadastrados.11" << endl;
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
  this_thread::sleep_for(chrono::seconds(5));
  cout << "\x1B[2J\x1B[H";
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
      cout << "Nome da mãe: " << user.motherName << endl;
      cout << "Ano do nascimento: " << user.birthYear << endl;
    }
    cout << "-------------------------" << endl;
  }
  this_thread::sleep_for(chrono::seconds(5));
  cout << "\x1B[2J\x1B[H";
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
    this_thread::sleep_for(chrono::seconds(3));
    cout << "\x1B[2J\x1B[H";
  }
}