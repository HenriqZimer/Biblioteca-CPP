#include "functions/User.h"
#include "../Utilities/Includes.h"
#include "../Biblioteca/Biblioteca.h"

using namespace std;

void userMenu() {

  int option;

  do {
    cout << "MENU USUÁRIOS" << endl;
    cout << "\n1. Cadastrar Usuário\n";
    cout << "2. Listar Usuários Cadastrados\n";
    cout << "3. Sair\n";
    printDivider();
    cout << "Quantidade de cadastro de usuários: " << Library::users.size() << endl;
    if (!Library::users.empty()) {
      cout << "Último usuário cadastrado: " << Library::users.back().name << endl;
    }
    printDivider();
    cout << "Escolha uma opção: ";
    cin >> option;
    cin.ignore();
    clear();

    switch (option) {
    case 1:
      registerUser();
      break;
    case 2:
      listUsers();
      break;
    case 3:
      break;
    default:
      invalidOption();
      break;
    }
  } while (option != 3);
}