#include <iostream>
#include <locale>
#include <thread> 
#include "src/Livros/CadastroLivros.h"
#include "src/Usuarios/CadastroUsuarios.h"
#include "src/Biblioteca/Biblioteca.h"

using namespace std;

int main() {
  setlocale(LC_ALL, "portuguese");

  int option;
  do {
    cout << "\x1B[2J\x1B[H";
    cout << "BIBLIOTECA VH" << endl;
    cout << "-------------------------" << endl;
    cout << "MENU PRINCIPAL" << endl;
    cout << "\n1. Menu Livros\n";
    cout << "2. Menu Usuários\n";
    cout << "3. Listar Livros\n";
    cout << "4. Listar Usuários\n";
    cout << "5. Sair\n";


    cout << "Escolha uma opção: ";
    cin >> option;
    cin.ignore();
    cout << "\x1B[2J\x1B[H";

    switch (option) {
    case 1:
      bookMenu();
      break;
    case 2:
      userMenu();
      break;
    case 3:
      Library::listBooks();
      break;
    case 4:
      Library::listUsers();
      break;
    }
  } while (option != 5);

  return 0;
}


