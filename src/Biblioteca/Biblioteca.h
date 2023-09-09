#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream> // É utilizado para operações de entrada e saída (cin, cout).
#include <locale.h> // É Utilizado para a chamada setlocale(LC_ALL, "portuguese"); que configura a localização.
#include <stdlib.h> // É utilizado para usar o nullprt;

#include <vector> // É utilizado para manipular a lista vetores.
#include <string> // É utilizado para manipular strings nos atributos do struct e para as funções de entrada/saída.

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