#pragma once
#include "src/cadastroLivros/functions/Book.h"
#include "src/cadastroUsuarios/functions/User.h"
#include <vector>

using namespace std;

class Library {
  public:
  static vector<Book> books;
  static vector<User> users;

  static void listBooks();
  static void listUsers();
};
