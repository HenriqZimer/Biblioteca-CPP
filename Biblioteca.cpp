#include <iostream>
#include <locale>
#include <thread> 
#include "src/cadastroLivros/cadastroLivros.h"
#include "src/cadastroUsuarios/CadastroUsuarios.h"
#include "Library.h"

using namespace std;

int main() {
  setlocale(LC_ALL, "portuguese");

  int option;
  do {
    cout << "\x1B[2J\x1B[H";
    cout << "BIBLIOTECA VH" << endl;
    cout << "-------------------------" << endl;
    cout << "MENU PRINCIPAL" << endl;
    cout << "\n1. Cadastrar Livro\n";
    cout << "2. Cadastrar Usuário\n";
    cout << "3. Listar Livros\n";
    cout << "4. Listar Usuários\n";
    cout << "5. Sair\n";
    cout << "Escolha uma opção: ";
    cin >> option;
    cin.ignore(); 
    cout << "\x1B[2J\x1B[H";

    switch (option) {
    case 1:
      menuCadastroLivros();
      break;
    case 2:
      menuCadastroUsuarios();
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


// iostream: Você está utilizando para operações de entrada e saída (cin, cout).
// clocale: Utilizado para a chamada setlocale(LC_ALL, "portuguese"); que configura a localização.
// vector: Utilizado para manipular a lista (vetor) de livros.
// string: Utilizado para manipular strings nos atributos do struct e para as funções de entrada/saída.
// thread: Utilizado para a função this_thread::sleep_for.
// chrono: Utilizado para especificar a duração do sono na função sleep_for.
