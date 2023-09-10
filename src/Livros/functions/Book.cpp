#include "Book.h"
#include "../../Utilities/Includes.h"
#include "../../Biblioteca/Biblioteca.h"

using namespace std;

// Funções Reutilizadas ------------------------------
void printSingleBook(const Book& book) {
  printDivider();
  cout << "Título: " << book.title << endl;
  cout << "Autor: " << book.author << endl;
  cout << "Ano de Publicação: " << book.publicationYear << endl;
  cout << "Número de Cópias: " << book.copyNumbers << endl;
  printDivider();
}

bool searchTitle(const Book& book, const string& input) {
  return book.title == input;
}

bool searchAuthor(const Book& book, const string& input) {
  return book.author == input;
}

bool searchYear(const Book& book, const string& input) {
  int year = stoi(input);
  return book.publicationYear == year;
}
// ---------------------------------------------------

// Função de Cadastro de Livros ----------------------
void registerBook() {
  Book newBook;

  cin.ignore();
  cout << "CADASTRANDO LIVRO !!!" << endl;
  printDivider();
  cout << "Digite o título: ";
  getline(cin, newBook.title);

  cout << "Digite o autor: ";
  getline(cin, newBook.author);

  cout << "Digite o ano de Publicação: ";
  cin >> newBook.publicationYear;

  cout << "Digite o número de cópias: ";
  cin >> newBook.copyNumbers;
  printDivider();

  Library::books.push_back(newBook);

  printBook(newBook);
}
// ---------------------------------------------------

// Função de Imprimir Livro depois do Cadastro -----
void printBook(const Book& book) {
  clear();
  cout << "Você cadastrou esse Livro: " << endl;
  printSingleBook(book);
  pauseAndClear();
}
// ---------------------------------------------------

// Função de Lista os Livros -------------------------
void listBooks() {
  clear();
  if (Library::books.empty()) {
    printDivider();
    cout << "Erro: Não há livros cadastrados." << endl;
    printDivider();
  }
  else {
    clear();
    cout << "LIVROS CADASTRADOS" << endl;
    for (const Book& book : Library::books) {
      printSingleBook(book);
    }
  }
  pauseAndClear();
}
// ---------------------------------------------------

// Função de Pesquisar Livros ------------------------
void searchBook() {
  int option;
  string input;
  bool found;

  // Define a function pointer
  bool (*searchFunction)(const Book&, const string&) = nullptr;

  clear();
  do {
    found = false;  // Redefina found para false no início de cada iteração
    cout << "PESQUISAR LIVRO" << endl;
    printDivider();
    cout << "1. Pesquisar por título" << endl;
    cout << "2. Pesquisar por autor" << endl;
    cout << "3. Pesquisar por ano de publicação" << endl;
    cout << "4. Sair\n";
    printDivider();
    cout << "Escolha uma opção: ";
    cin >> option;
    clear();
    cin.ignore();

    switch (option) {

    case 1:
      cout << "PESQUISANDO LIVRO" << endl;
      printDivider();
      cout << "Digite o título: ";
      searchFunction = searchTitle;
      break;

    case 2:
      cout << "PESQUISANDO LIVRO" << endl;
      printDivider();
      cout << "Digite o autor: ";
      searchFunction = searchAuthor;
      break;

    case 3:
      cout << "PESQUISANDO LIVRO" << endl;
      printDivider();
      cout << "Digite o ano de publicação: ";
      searchFunction = searchYear;
      break;

    case 4:
      return;

    default:
      invalidOption();
      return;
    }

    getline(cin, input);

    if (searchFunction) {
      for (const Book& book : Library::books) {
        if (searchFunction(book, input)) {
          printSingleBook(book);
          found = true;
        }
      }
    }
    pauseAndClear();

    if (!found && option != 4) {
      printDivider();
      cout << "Erro: Livro não encontrado." << endl;
      printDivider();
      pauseAndClear();
    }
  } while (option != 4);
}
// ---------------------------------------------------
