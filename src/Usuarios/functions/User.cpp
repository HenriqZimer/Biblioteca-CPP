#include "User.h"
#include "../../Utilities/Includes.h"
#include "../../Biblioteca/Biblioteca.h"

using namespace std;

// Funções Reutilizadas ------------------------------
void printSingleUser(const User& user) {
  printDivider();
  cout << "Usuário: " << user.name << endl;
  cout << "Numero de Verificação: " << user.verificationNumber << endl;
  cout << "Quantidade de Empréstimos: " << user.numberLoans << endl;
  printDivider();
}
// ---------------------------------------------------

// Função de Cadastro de Usuario ---------------------
void registerUser() {
  User newUser;

  cout << "CADASTRANDO USUÁRIO!!!" << endl;
  printDivider();
  cout << "Digite o nome do usuário: ";
  getline(cin, newUser.name);

  cout << "Digite um número para sua verificação: ";
  cin >> newUser.verificationNumber;
  cin.ignore();
  printDivider();

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
    cout << "Erro: Não há usuários cadastrados." << endl;
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