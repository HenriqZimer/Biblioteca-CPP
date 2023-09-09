#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

struct User {
  string name;
  int verificationNumber;
  int numberLoans;
};

void printUser(const User& user);
void registerUser();
void listUsers();

#endif