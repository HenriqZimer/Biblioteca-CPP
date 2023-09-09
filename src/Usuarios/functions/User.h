#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

using namespace std;

struct User {
  string name;
  int verificationNumber;
  int numberLoans;
  vector<string> booksLoans;
};

void printUser(const User& user);
void registerUser();
void listUsers();

#endif