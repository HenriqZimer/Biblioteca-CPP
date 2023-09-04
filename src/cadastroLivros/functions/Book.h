#include <vector>
#include <string>

using namespace std;

struct Book {
  string title;
  string author;
  int publicationYear;
  int copyNumbers;
};

void printBook(const Book& book);
void registerBook(vector<Book>& books);
void listBooks(const vector<Book>& books);
