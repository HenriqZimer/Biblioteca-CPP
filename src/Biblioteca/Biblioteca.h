#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <locale.h>
#include <thread>
#include <stdlib.h>

#include <vector>
#include <string>

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
  static bool userExists(const string& name);
  // static bool numberExists(const string& verificationNumber);
  static bool bookExists(const string& title);
  static bool authorExists(const string& author);
};

#endif