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

string formatWithLeadingZero(int value) {
  if (value < 10) {
    return "0" + to_string(value);
  }
  else {
    return to_string(value);
  }
}

// string formatDate(int dateValue) {
//   string dateStr = to_string(dateValue);
//   return "Dia: " + formatWithLeadingZero(stoi(dateStr.substr(0, 2))) +
//     " Mês: " + formatWithLeadingZero(stoi(dateStr.substr(2, 2))) +
//     " Ano: " + dateStr.substr(4, 4);
// }

void printSingleLoan(const Loan& loan) {
  printDivider();
  cout << "Usuário: " << loan.user << endl;
  cout << "Título: " << loan.title << endl;
  cout << "Autor: " << loan.author << endl;
  cout << "Dia do Empréstimo: " << loan.loanDay << endl;
  cout << "Dia da Devolução: " << loan.returnDay << endl;
  printDivider();
}
// ---------------------------------------------------

// Função de Cadastro de Emprestimo ------------------
void registerLoan() {
  Loan newLoan;
  int loanTime, verificationNumber;

  cout << "EMPRESTANDO LIVRO !!!" << endl;
  printDivider();

  cout << "Digite o nome do Usuario: ";
  getline(cin, newLoan.user);

  User* user = findUser(newLoan.user);
  if (!checkExistence(user, "Usuário não encontrado no sistema.")) return;

  cout << "Digite o numero de verificação: ";
  cin >> verificationNumber;
  cin.ignore();


  if (!Library::numberExists(verificationNumber)) {
    cout << "Erro: Usuário não encontrado no sistema." << endl;
    pauseAndClear();
    return;
  }

  cout << "Digite o título: ";
  getline(cin, newLoan.title);

  Book* book = findBook(newLoan.title);
  if (!checkExistence(book, "Livro não encontrado no sistema.")) return;

  cout << "Digite o autor: ";
  getline(cin, newLoan.author);
  if (!checkExistence(Library::authorExists(newLoan.author), "Autor não encontrado no sistema.")) return;

  int day, month, year;

  // Solicitar o dia do empréstimo
  do {
    cout << "Digite o dia do seu Empréstimo (1-31): ";
    cin >> day;
    cin.ignore();
    if (day < 1 || day > 31) {
      cout << "Dia inválido! Tente novamente." << endl;
    }
  } while (day < 1 || day > 31);

  // Solicitar o mês do empréstimo
  do {
    cout << "Digite o mês do seu Empréstimo (1-12): ";
    cin >> month;
    cin.ignore();
    if (month < 1 || month > 12) {
      cout << "Mês inválido! Tente novamente." << endl;
    }
  } while (month < 1 || month > 12);

  // Solicitar o ano do empréstimo
  cout << "Digite o ano do seu Empréstimo: ";
  cin >> year;
  cin.ignore();
  cout << "Você tem 7 dias para devolver seu Empréstimo (clique ENTER para continuar)";
  cin.ignore();

  newLoan.loanDay = stoi(formatWithLeadingZero(day) + formatWithLeadingZero(month) + to_string(year));

  day += 7;

  while (day > 30) {
    month++;
    day -= 30;

    if (month > 12) {
      year++;
      month = 1;
    }
  }

  newLoan.returnDay = stoi(formatWithLeadingZero(day) + formatWithLeadingZero(month) + to_string(year));

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
  int verificationNumber;

  cout << "DEVOLUÇÃO DE LIVRO" << endl;
  printDivider();


  cout << "Digite o nome do Usuario: ";
  getline(cin, userName);

  if (!Library::userExists(userName)) {
    cout << "Erro: Usuário não encontrado no sistema." << endl;
    pauseAndClear();
    return;
  }

  cout << "Digite o numero de verificação: ";
  cin >> verificationNumber;
  cin.ignore();

  if (!Library::numberExists(verificationNumber)) {
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
  getline(cin, bookAuthor);

  if (!Library::authorExists(bookAuthor)) {
    cout << "Erro: Autor não encontrado no sistema." << endl;
    pauseAndClear();
    return;
  }

  int returnDay, returnMonth, returnYear;

  // Solicitar o dia da devolução
  do {
    cout << "Digite o dia da devolução (1-31): ";
    cin >> returnDay;
    cin.ignore();
    if (returnDay < 1 || returnDay > 31) {
      cout << "Dia inválido! Tente novamente." << endl;
    }
  } while (returnDay < 1 || returnDay > 31);

  // Solicitar o mês da devolução
  do {
    cout << "Digite o mês da devolução (1-12): ";
    cin >> returnMonth;
    cin.ignore();
    if (returnMonth < 1 || returnMonth > 12) {
      cout << "Mês inválido! Tente novamente." << endl;
    }
  } while (returnMonth < 1 || returnMonth > 12);

  // Solicitar o ano da devolução
  cout << "Digite o ano da devolução: ";
  cin >> returnYear;
  cin.ignore();

  int actualReturnDate = stoi(formatWithLeadingZero(returnDay) + formatWithLeadingZero(returnMonth) + to_string(returnYear));

  for (auto i = Library::loans.begin(); i != Library::loans.end(); ++i) {
    if (i->user == userName && i->title == bookTitle) {

      cout << "Data de devolução inserida: " << actualReturnDate << endl;
      cout << "Data de devolução prevista: " << i->returnDay << endl;

      if (actualReturnDate > i->returnDay) {
        cout << "Aviso: Você está devolvendo este livro após a data de devolução." << endl;
        cout << "Por favor, seja pontual na próxima vez." << endl;
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
  clear();

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
  pauseAndClear();
}

