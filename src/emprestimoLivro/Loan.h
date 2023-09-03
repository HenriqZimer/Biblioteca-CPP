#include <vector>
#include <string>

using namespace std;

struct Loan {
  string title;
  string author;
  int loanDay;
  int returnDay;
};

void printLoan(const Loan& loan);
void registerLoan(vector<Loan>& loans);
void listLoans(const vector<Loan>& loans);
