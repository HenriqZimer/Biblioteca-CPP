#ifndef LOAN_H
#define LOAN_H

#include <string>

using namespace std;

struct Loan {
  string user;
  string title;
  string author;
  string loanDay;
  int returnDay;
};

void printLoan(const Loan& loan);
void registerLoan();
void bookReturn();
void listLoans();
void printUserBooks();

#endif