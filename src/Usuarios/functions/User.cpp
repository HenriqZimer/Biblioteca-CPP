#include <iostream>
#include <thread>
#include <chrono>
#include <stdlib.h>
#include "User.h"
#include "../../Utilities/Includes.h"
#include "../../Biblioteca/Biblioteca.h"

using namespace std;

// Funções Reutilizadas ------------------------------
void printSingleUser(const User& user) {
  cout << "-------------------------" << endl;
  cout << "Usuário: " << user.name << endl;
  cout << "Numero de Verificação: " << user.verificationNumber << endl;
  cout << "-------------------------" << endl;
}
// ---------------------------------------------------

// Função de Cadastro de Usuario ---------------------
void registerUser() {
  User newUser;

  cout << "CADASTRANDO USUÁRIO!!!" << endl;
  cout << "-------------------------" << endl;
  cout << "Digite o nome do usuário: ";
  getline(cin, newUser.name);

  cout << "Digite um número para sua verificação: ";
  cin >> newUser.verificationNumber;
  cout << "-------------------------" << endl;

  newUser.numberLoans = 0;

  Library::users.push_back(newUser);

  printUser(newUser);
}
// ---------------------------------------------------

// Função de Imprimir Usuario depois do Cadastro -----
void printUser(const User& user) {
  clear();
  cout << "Você cadastrou esse usuário: " << endl;
  printSingleUser(user);
  pauseAndClear();
}
// ---------------------------------------------------

// Função de Lista os Usuarios -----------------------
void listUsers() {
  clear();
  if (Library::users.empty()) {
    cout << "Não há usuários cadastrados." << endl;
  }
  else {
    cout << "USUÁRIOS CADASTRADOS:" << endl;
    for (const User& user : Library::users) {
      printSingleUser(user);
    }
  }
  pauseAndClear();
}
// ---------------------------------------------------