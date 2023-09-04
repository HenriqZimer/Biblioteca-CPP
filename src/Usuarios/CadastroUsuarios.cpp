#include <iostream>
#include <locale.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include "functions/User.h"
#include "../Biblioteca/Biblioteca.h"

using namespace std;

void userMenu() {
  setlocale(LC_ALL, "portuguese");

  int option;

  do {
    cout << "MENU USUÁRIOS" << endl;
    cout << "\n1. Cadastrar Usuario\n";
    cout << "2. Listar Usuários Cadastrados\n";
    cout << "3. Sair\n";
    cout << "-------------------------" << endl;
    cout << "Número de usuários registrados: " << Library::users.size() << endl;
    if (!Library::users.empty()) {
      cout << "Último usuário registrado: " << Library::users.back().name << endl;
    }
    cout << "-------------------------" << endl;
    cout << "Escolha uma opção: ";
    cin >> option;
    cin.ignore();
    cout << "\x1B[2J\x1B[H";

    if (option == 1) {
      registerUser();
    }
    else if (option == 2) {
      listUsers();
      this_thread::sleep_for(chrono::seconds(5));
      cout << "\x1B[2J\x1B[H";
    }
  } while (option != 3);
}