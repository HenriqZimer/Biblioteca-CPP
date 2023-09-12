#include "../Utilities/Includes.h"
#include "Biblioteca.h"

using namespace std;

vector<Book> Library::books;
vector<User> Library::users;
vector<Loan> Library::loans;

// Funções de verificação de existência de usuário, livro, autor e número de verificação
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

string Library::getUserWithMostLoans() {
  if (users.empty()) {
    return "Nenhum usuário registrado";
  }

  string topUser = users[0].name;
  int maxLoans = users[0].booksLoans.size();

  for (const User& user : users) {
    if (user.booksLoans.size() > maxLoans) {
      maxLoans = user.booksLoans.size();
      topUser = user.name;
    }
  }

  return topUser;
}

string Library::getMostLoanedBook() {
  if (loans.empty()) {
    return "Nenhum empréstimo realizado";
  }

  map<string, int> loanCounts;

  // Conta quantas vezes cada livro foi emprestado
  for (const Loan& loan : loans) {
    loanCounts[loan.title]++;
  }

  // Encontra o livro com a contagem máxima de empréstimos
  string topBook = loans[0].title;
  int maxLoans = loanCounts[topBook];

  for (const auto& pair : loanCounts) {
    if (pair.second > maxLoans) {
      maxLoans = pair.second;
      topBook = pair.first;
    }
  }

  return topBook;
}


// --------------------------------------------------------------------------------------------

// Função que apresenta as estastísticas ------------------------------------------------------
void Library::generalStatistics() {
  clear();
  cout << "ESTATÍSTICAS GERAIS" << endl;
  printDivider();
  cout << "Quantidade de cadastro de livros: " << Library::books.size() << endl;
  cout << "Quantidade de cadastro de usuários: " << Library::users.size() << endl;
  cout << "Quantidade de registro de empréstimos: " << Library::loans.size() << endl;
  cout << "Livro mais Popular: " << Library::getMostLoanedBook() << endl;
  cout << "Usuário mais Ativo: " << Library::getUserWithMostLoans() << endl;

  printDivider();
  pauseAndClear(8);
}
// --------------------------------------------------------------------------------------------