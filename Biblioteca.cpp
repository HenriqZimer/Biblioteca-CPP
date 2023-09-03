#include <iostream>
#include <locale>
#include <thread> 

using namespace std;

int main() {
  setlocale(LC_ALL, "portuguese");

  int option;
  do {
    cout << "BIBLIOTECA VH" << endl;
    cout << "-------------------------" << endl;
    cout << "MENU PRINCIPAL" << endl;
    cout << "\n1. Cadastar Livro\n";
    cout << "2. Cadastrar Usuário\n";
    cout << "3. Emprestar Livros\n";
    cout << "4. Sair\n";
    cout << "Escolha uma opção: ";
    cin >> option;
    cout << "\x1B[2J\x1B[H";

  } while (option != 4);

  return 0;
}

// iostream: Você está utilizando para operações de entrada e saída (cin, cout).
// clocale: Utilizado para a chamada setlocale(LC_ALL, "portuguese"); que configura a localização.
// vector: Utilizado para manipular a lista (vetor) de livros.
// string: Utilizado para manipular strings nos atributos do struct e para as funções de entrada/saída.
// thread: Utilizado para a função this_thread::sleep_for.
// chrono: Utilizado para especificar a duração do sono na função sleep_for.