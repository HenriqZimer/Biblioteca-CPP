#include <vector>
#include <string>

using namespace std;

struct User {
  string name;
  int birthYear;
  string motherName;
};

void printUser(const User& user);
void registerUser(vector<User>& users);
void listUsers(const vector<User>& users);
