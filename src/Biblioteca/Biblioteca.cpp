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
      printDivider();
      cout << "Título: " << book.title << endl;
      cout << "Autor: " << book.author << endl;
      cout << "Ano de Publicação: " << book.publicationYear << endl;
      cout << "Número de Cópias: " << book.copyNumbers << endl;
    }
    printDivider();
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
      printDivider();
      cout << "Nome: " << user.name << endl;
      cout << "Número de verificação: " << user.verificationNumber << endl;
      cout << "Quantidade de livros emprestados: " << user.numberLoans << endl;
    }
    printDivider();
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
      printDivider();
      cout << "Usuário: " << loan.user << endl;
      cout << "Título: " << loan.title << endl;
      cout << "Autor: " << loan.author << endl;
      cout << "Dia do Empréstimo: " << loan.loanDay << endl;
      cout << "Dia da Devolução: " << loan.returnDay << endl;
    }
    printDivider();
    pauseAndClear();
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

bool Library::numberExists(int verificationNumber) {
  for (const User& user : users) {
    if (user.verificationNumber == verificationNumber) {
      return true;
    }
  }
  return false;
}

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

void Library::generalStatistics() {
  clear();
  cout << "ESTATÍSTICAS GERAIS" << endl;
  printDivider();
  cout << "Quantidade de registro de empréstimos: " << Library::loans.size() << endl;
  cout << "Livro mais Popular: " << Library::loans.size() << endl;
  cout << "Usuário mais Ativo: " << Library::loans.size() << endl;

  printDivider();
  pauseAndClear();

}
