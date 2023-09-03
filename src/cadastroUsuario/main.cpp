#include "User.h"
#include <iostream>
#include <locale.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <thread>
#include <chrono>

using namespace std;

int main() {
  setlocale(LC_ALL, "portuguese");
  vector<User> users;

  int option;

  do {
    cout << "MENU CADASTRO DE USUÁRIOS" << endl;
    cout << "\n1. Registrar Usuario\n";
    cout << "2. Listar Usuários\n";
    cout << "3. Sair\n";
    cout << "Escolha uma opção: ";
    cin >> option;
    cout << "\x1B[2J\x1B[H";

    if (option == 1) {
      registerUser(users);
    }
    else if (option == 2) {
      listUsers(users);
      this_thread::sleep_for(chrono::seconds(5));
      cout << "\x1B[2J\x1B[H";
    }
  } while (option != 3);

  return 0;
}

// Comando Build g++ main.cpp User.cpp -o output.exe, lembre de estar no diretorio do main.cpp no terminal