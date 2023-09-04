#ifndef USER_H
#define USER_H

#include <vector>
#include <string>

using namespace std;

struct User {
  string name;
  int birthYear;
  string motherName;
};

void printUser(const User& user);
void registerUser();
void listUsers();

#endif