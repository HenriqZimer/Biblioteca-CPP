#include "Includes.h"
#include <iostream>

void printDivider() {
  cout << "-------------------------" << endl;
}

void invalidOption() {
  printDivider();
  cout << "Opção inválida." << endl;
  printDivider();
  pauseAndClear();
}
