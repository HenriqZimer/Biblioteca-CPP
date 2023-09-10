#include <regex>
#include "Loan.h"
#include "../../Utilities/Includes.h"
#include "../../Biblioteca/Biblioteca.h"

using namespace std;

// Funções Reutilizadas ------------------------------
bool checkExistence(bool condition, const string& errorMessage) {
  if (!condition) {
    cout << "Erro: " << errorMessage << endl;
    pauseAndClear();
    return false;
  }
  return true;
}

User* findUser(const string& userName) {
  for (User& user : Library::users) {
    if (user.name == userName) {
      return &user;
    }
  }
  return nullptr;
}

Book* findBook(const string& bookTitle) {
  for (Book& book : Library::books) {
    if (book.title == bookTitle) {
      return &book;
    }
  }
  return nullptr;
}

void printSingleLoan(const Loan& loan) {
  printDivider();
  cout << "Usuário: " << loan.user << endl;
  cout << "Título: " << loan.title << endl;
  cout << "Autor: " << loan.author << endl;
  cout << "Dia do Empréstimo: " << loan.loanDay << endl;
  cout << "Dia da Devolução: " << loan.returnDay << endl;
  printDivider();
}

regex datePattern(R"(\d{2}\d{2}\d{4})"); // Expressão regular para a data.

// ---------------------------------------------------

// Função de Cadastro de Emprestimo ------------------
void registerLoan() {
  Loan newLoan;
  int loanTime;

  cout << "EMPRESTANDO LIVRO !!!" << endl;
  printDivider();

  cout << "Digite o nome do Usuario: ";
  getline(cin, newLoan.user);

  User* user = findUser(newLoan.user);
  if (!checkExistence(user, "Usuário não encontrado no sistema.")) return;

  cout << "Digite o título: ";
  getline(cin, newLoan.title);

  Book* book = findBook(newLoan.title);
  if (!checkExistence(book, "Livro não encontrado no sistema.")) return;

  cout << "Digite o autor: ";
  getline(cin, newLoan.author);
  if (!checkExistence(Library::authorExists(newLoan.author), "Autor não encontrado no sistema.")) return;

// Formatador de data em Regex -----------------------
  do {
    cout << "Digite o dia do seu Empréstimo no formato DDMMYYYY: ";
    getline(cin, newLoan.loanDay);

    if (!regex_match(newLoan.loanDay, datePattern)) {
      cout << "Formato de data inválido! Tente novamente." << endl;
    }

  } while (!regex_match(newLoan.loanDay, datePattern));

  int day = stoi(newLoan.loanDay.substr(0, 2));
  int month = stoi(newLoan.loanDay.substr(2, 2));
  int year = stoi(newLoan.loanDay.substr(4, 4));

  cout << "Digite quantidade de dia(s) para seu Empréstimo: ";
  cin >> loanTime;

  day += loanTime;

  while (day > 30) {
    month++;
    day -= 30;

    if (month > 12) {
      year++;
      month = 1;
    }
  }

  newLoan.returnDay = day + month * 100 + year * 10000;

  for (User& user : Library::users) {
    if (user.name == newLoan.user) {
      user.numberLoans++;
      user.booksLoans.push_back(newLoan.title);
      break;
    }
  }

  for (Book& book : Library::books) {
    if (book.author == newLoan.author && book.title == newLoan.title) {
      book.copyNumbers--;
      break;
    }
  }

  Library::loans.push_back(newLoan);

  printLoan(newLoan);
}
// ---------------------------------------------------

// Função de Imprimir Emprestimo depois do Cadastro ---
void printLoan(const Loan& loan) {
  clear();
  cout << "Você fez o empréstimo desse Livro: " << endl;
  printSingleLoan(loan);
  pauseAndClear();
}
// ---------------------------------------------------

// Função de Lista os Emprestimos --------------------
void listLoans() {
  clear();
  if (Library::loans.empty()) {
    cout << "Não há empréstimos cadastrados." << endl;
  }
  else {
    cout << "EMPRÉSTIMOS CADASTRADOS:" << endl;
    for (const Loan& loan : Library::loans) {
      printSingleLoan(loan);
    }
  }
  pauseAndClear();
}
// ---------------------------------------------------

// Função de Devolução dos Emprestimos ---------------
void bookReturn() {
  string userName, bookTitle, bookAuthor;
  // int verificationNumber;

  cout << "DEVOLUÇÃO DE LIVRO" << endl;
  printDivider();

  // cout << "Digite o numero de verificação: ";
  // getline(cin, verificationNumber);

  if (!Library::numberExists) {
    cout << "Erro: Usuário não encontrado no sistema." << endl;
    pauseAndClear();
    return;
  }

  cout << "Digite o nome do Usuario: ";
  getline(cin, userName);

  if (!Library::userExists(userName)) {
    cout << "Erro: Usuário não encontrado no sistema." << endl;
    pauseAndClear();
    return;
  }

  cout << "Digite o título do livro sendo devolvido: ";
  getline(cin, bookTitle);

  if (!Library::bookExists(bookTitle)) {
    cout << "Erro: Livro não encontrado no sistema." << endl;
    pauseAndClear();
    return;
  }

  cout << "Digite o Autor do livro sendo devolvido: ";
  getline(cin, bookTitle);

  if (!Library::authorExists(bookAuthor)) {
    cout << "Erro: Autor não encontrado no sistema." << endl;
    pauseAndClear();
    return;
  }

  cout << "Digite a data de devolução no formato DDMMYYYY: ";
  string returnDate;
  getline(cin, returnDate);

  if (!regex_match(returnDate, datePattern)) {
    cout << "Formato de data inválido! Tente novamente." << endl;
    return;
  }

  int returnDay = stoi(returnDate.substr(0, 2));
  int returnMonth = stoi(returnDate.substr(2, 2));
  int returnYear = stoi(returnDate.substr(4, 4));
  int actualReturnDate = returnDay + returnMonth * 100 + returnYear * 10000;

  for (auto i = Library::loans.begin(); i != Library::loans.end(); ++i) {
    if (i->user == userName && i->title == bookTitle) {

      if (actualReturnDate > i->returnDay) {
        cout << "Aviso: Você está devolvendo este livro após a data de devolução. Por favor, seja pontual na próxima vez." << endl;
      }

      Library::loans.erase(i);

      for (User& user : Library::users) {
        if (user.name == userName) {
          user.numberLoans--;
          break;
        }
      }

      clear();
      cout << "Devolução registrada com sucesso!" << endl;
      pauseAndClear();
      return;
    }
  }
  clear();
  cout << "Erro: Empréstimo não encontrado." << endl;
  pauseAndClear();
}
// ---------------------------------------------------

// Função de Imprimir Emprestimos por Usuário --------
void printUserBooks() {
  string userName;

  cout << "EMPRÉSTIMOS POR USUÁRIOS" << endl;
  printDivider();
  cout << "Digite o nome do Usuario: ";
  getline(cin, userName);

  User* foundUser = nullptr;
  for (User& user : Library::users) {
    if (user.name == userName) {
      foundUser = &user;
      break;
    }
  }

  if (!foundUser) {
    cout << "Erro: Usuário não encontrado no sistema." << endl;
    pauseAndClear();
    return;
  }

  if (foundUser->booksLoans.empty()) {
    cout << "Erro: Não há emprestimos desse usuário no sistema." << endl;
    pauseAndClear();
    return;
  }

  cout << "Livros emprestados por " << foundUser->name << ":" << endl;

  for (const string& bookTitle : foundUser->booksLoans) {
    cout << "- " << bookTitle << endl;
  }
}

