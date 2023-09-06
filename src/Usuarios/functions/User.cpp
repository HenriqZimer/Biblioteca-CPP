#include <iostream>
#include <thread>
#include <chrono>
#include <stdlib.h>
#include "User.h"
#include "../../Utilities/Includes.h"
#include "../../Biblioteca/Biblioteca.h"

using namespace std;

void registerUser() {
  User newUser;

  cout << "CADASTRANDO USUÁRIO!!!" << endl;
  cout << "-------------------------" << endl;
  cout << "Digite o nome do usuário: ";
  getline(cin, newUser.name);

  cout << "Digite o seu número de Verificação: ";
  cin >> newUser.verificationNumber;
  cout << "-------------------------" << endl;

  newUser.numberLoans = 0;

  Library::users.push_back(newUser);

  printUser(newUser);
}

void printUser(const User& user) {
  clear();
  cout << "Você cadastrou esse usuário: " << endl;
  cout << "-------------------------" << endl;
  cout << "Nome: " << user.name << endl;
  cout << "Numero de Verificação: " << user.verificationNumber << endl;
  cout << "-------------------------" << endl;
  pauseAndClear();
}

void listUsers() {
  clear();
  if (Library::users.empty()) {
    cout << "Não há usuários cadastrados." << endl;
  }
  else {
    cout << "USUÁRIOS CADASTRADOS:" << endl;
    for (const User& user : Library::users) {
      cout << "-------------------------" << endl;
      cout << "Nome: " << user.name << endl;
      cout << "Número de verificação: " << user.verificationNumber << endl;
    }
    cout << "-------------------------" << endl;
    pauseAndClear();
  }
}
