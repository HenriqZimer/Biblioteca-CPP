#include "User.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <stdlib.h>

using namespace std;

void printUser(const User& user) {
  cout << "\x1B[2J\x1B[H";
  cout << "Você cadastrou esse usuário: " << endl;
  cout << "-------------------------" << endl;
  cout << "Nome: " << user.name << endl;
  cout << "Nome da mãe: " << user.motherName << endl;
  cout << "Ano de nascimento: " << user.birthYear << endl;
  cout << "-------------------------" << endl;
  this_thread::sleep_for(chrono::seconds(3));
  cout << "\x1B[2J\x1B[H";
}

void registerUser(std::vector<User>& users) {
  User newUser;

  cin.ignore();
  cout << "CADASTRANDO USUÁRIO!!!" << endl;
  cout << "-------------------------" << endl;
  cout << "Digite o nome do usuário: ";
  getline(cin, newUser.name);

  cout << "Digite o Nome da mãe: ";
  getline(cin, newUser.motherName);

  cout << "Digite o ano de nascimento: ";
  cin >> newUser.birthYear;
  cout << "-------------------------" << endl;

  users.push_back(newUser);

  printUser(newUser);
}

void listUsers(const std::vector<User>& users) {
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
