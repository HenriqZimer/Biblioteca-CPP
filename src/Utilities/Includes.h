#ifndef INCLUDES_H
#define INCLUDES_H

#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

inline void pauseAndClear(int seconds = 3) {
  this_thread::sleep_for(chrono::seconds(seconds));
  cout << "\x1B[2J\x1B[H";
}
inline void pause(int seconds = 3) {
  this_thread::sleep_for(chrono::seconds(seconds));
}
inline void clear() {
  cout << "\x1B[2J\x1B[H";
}

#endif 
