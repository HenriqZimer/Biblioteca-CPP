#ifndef LOAN_H
#define LOAN_H

#include <vector>
#include <string>

using namespace std;

struct Loan {
  string user;
  string title;
  string author;
  int loanDay;
  int returnDay;
};

void printLoan(const Loan& loan);
void registerLoan();
void listLoans();

#endif