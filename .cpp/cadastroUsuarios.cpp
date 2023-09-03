#include <iostream>
#include <locale>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <stdlib.h>

using namespace std;

struct User {
  string name;
  int birthYear;
  string motherName;
};

void printUser(const User& user) {
  cout << "\x1B[2J\x1B[H";
  cout << "Voc� cadastrou esse usu�rio: " << endl;
  cout << "-------------------------" << endl;
  cout << "Nome: " << user.name << endl;
  cout << "Nome da m�e: " << user.motherName << endl;
  cout << "Ano de nascimento: " << user.birthYear << endl;
  cout << "-------------------------" << endl;
  this_thread::sleep_for(chrono::seconds(3));
  cout << "\x1B[2J\x1B[H";
}

void registerUser(vector<User>& users) {
  User newUser;

  cin.ignore();
  cout << "CADASTRANDO USU�RIO !!!" << endl;
  cout << "-------------------------" << endl;
  cout << "Digite o nome do usu�rio: ";
  getline(cin, newUser.name);

  cout << "Digite o Nome da m�e: ";
  getline(cin, newUser.motherName);

  cout << "Digite o ano de nascimento: ";
  cin >> newUser.birthYear;
  cout << "-------------------------" << endl;

  users.push_back(newUser);

  printUser(newUser);
}

void listUsers(vector<User>& users) {
  if (users.empty()) {
    cout << "N�o h� usu�rios cadastrados." << endl;
  }
  else {
    cout << "USU�RIOS CADASTRADOS:" << endl;
    for (const User& user : users) {
      cout << "-------------------------" << endl;
      cout << "Nome: " << user.name << endl;
      cout << "Nome da m�e: " << user.motherName << endl;
      cout << "Ano do nascimento: " << user.birthYear << endl;
    }
    cout << "-------------------------" << endl;
  }
}

int main() {
  setlocale(LC_ALL, "portuguese");
  vector<User> users;

  int option;
  do {
    cout << "MENU CADASTRO DE USU�RIOS" << endl;
    cout << "\n1. Registrar Usuario\n";
    cout << "2. Listar Usu�rios\n";
    cout << "3. Sair\n";
    cout << "Escolha uma op��o: ";
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
