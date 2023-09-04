#include <iostream>
#include "Biblioteca.h"

using namespace std;

vector<Book> Library::books;
vector<User> Library::users;

void Library::listBooks() {
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
}

void Library::listUsers() {
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
}
