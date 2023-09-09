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

bool searchByTitle(const Book& book, const string& input) {
  return book.title == input;
}

bool searchByAuthor(const Book& book, const string& input) {
  return book.author == input;
}

bool searchByYear(const Book& book, const string& input) {
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
    cout << "Não há livros cadastrados." << endl;
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
  bool found = false;

  // Define a function pointer
  bool (*searchFunction)(const Book&, const string&) = nullptr;

  clear();
  do{
  cout << "PESQUISAR LIVRO" << endl;
  printDivider();
  cout << "1. Pesquisar por título" << endl;
  cout << "2. Pesquisar por autor" << endl;
  cout << "3. Pesquisar por ano de publicação" << endl;
  cout << "0. Sair\n";
  printDivider();
  cout << "Escolha uma opção: ";
  cin >> option;
  clear();

  cin.ignore();
  cout << "PESQUISANDO LIVRO" << endl;
  printDivider();

  switch (option) {
  case 1:
    cout << "Digite o título: ";
    searchFunction = searchByTitle;
    break;

  case 2:
    cout << "Digite o autor: ";
    searchFunction = searchByAuthor;
    break;

  case 3:
    cout << "Digite o ano de publicação: ";
    searchFunction = searchByYear;
    break;

  default:
    printDivider();
    cout << "Opção inválida." << endl;
    return;
  }

  getline(cin, input);
  clear();

  for (const Book& book : Library::books) {
    if (searchFunction(book, input)) {
      printSingleBook(book);
      found = true;
      break;
    }
  }

  if (!found) {
    cout << "PESQUISANDO LIVRO" << endl;
    printDivider();
    cout << "Livro não encontrado." << endl;
  }
} while (option != 0);
  pauseAndClear();
}
// ---------------------------------------------------
