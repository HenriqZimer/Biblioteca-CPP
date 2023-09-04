#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <vector>
#include "../Livros/functions/Book.h"
#include "../Usuarios/functions/User.h"

using namespace std;

class Library {
  public:
  static vector<Book> books;
  static vector<User> users;

  static void listBooks();
  static void listUsers();
};

#endif