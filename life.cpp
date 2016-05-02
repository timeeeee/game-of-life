#include "life.h"

const char LIVE = 'x';
const char DEAD = ' ';

Life::Life(unsigned int num_rows, unsigned int num_cols) {
  rows = num_rows;
  cols = num_cols;
  length = rows * cols;
  board = new bool[length];
  clear();
}

Life::~Life() {
  delete[] board;
}

void Life::clear() {
  for (int i = 0; i < length; i++) {
    board[i] = false;
  }
}

void Life::get_string(char * string) {
  for (int i = 0; i < length; i++) {
    if (board[i]) {
      string[i] = LIVE;
    } else {
      string[i] = DEAD;
    }
  }
}

void Life::fpentamino() {
  // Clear board and draw an f-pentamino in the center
  clear();
}

void Life::random() {
  // Randomly fill half of the board spaces
  random(.5);
}

void Life::random(float r) {
  // Fill spaces at random, with probability r
  clear();
}

void Life::step() {
  // Advance life by one step
  
}
