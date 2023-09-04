#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include "../Livros/functions/Book.h"
#include "../Usuarios/functions/User.h"
#include "../Emprestimos/functions/Loan.h"

using namespace std;

class Library {
  public:
  static vector<Book> books;
  static vector<User> users;
  static vector<Loan> loans;

  static void listBooksMain();
  static void listUsersMain();
  static void listLoansMain();
};

#endif