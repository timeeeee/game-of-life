#include <cstdlib>
#include <ctime>

#include "life.h"

const char LIVE = 'x';
const char DEAD = ' ';

Life::Life(unsigned int num_rows, unsigned int num_cols) {
  rows = num_rows;
  cols = num_cols;
  length = rows * cols;
  board = new bool[length];
  clear();

  srand (static_cast <unsigned> (time(0)));
}

Life::~Life() {
  delete[] board;
}

bool Life::get(unsigned int row, unsigned int col) {
  row %= rows;
  col %= cols;
  return board[row * cols + col];
}
  

void Life::set(unsigned int row, unsigned int col, bool value) {
  row %= rows;
  col %= cols;
  board[row * cols + col] = value;
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

  /*
     xx
    xx
     x
  */
  unsigned int center_row = rows / 2;
  unsigned int center_col = cols / 2;
  set(center_row - 1, center_col, LIVE);
  set(center_row - 1, center_col + 1, LIVE);
  set(center_row, center_col - 1, LIVE);
  set(center_row, center_col, LIVE);
  set(center_row + 1, center_col, LIVE);
}

void Life::random() {
  // Randomly fill half of the board spaces
  random(.5);
}

void Life::random(float r) {
  // Fill spaces at random, with probability r
  clear();

  // make sure r is within reason
  if (r < 0) r = 0;
  if (r > 1) r = 1;

  for (int i = 0; i < length; i++) {
    float rand_val = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    if (rand_val < r) board[i] = LIVE;
  }
}

void Life::step() {
  // Advance life by one step
  
}
