#include <ncurses.h>

#include "life.h"

int main() {
  // ----- ncurses setup -----

  // initialize ncurses screen
  initscr();

  // disable tty char buffering to get one character at a time
  cbreak();

  // don't echo typed characters
  noecho();

  // enable capture of special keys
  keypad(stdscr, TRUE);

  // do fun stuff here
  int rows, cols;
  getmaxyx(stdscr, rows, cols);

  char *life_string;
  life_string = new char[rows * cols];
  Life board(rows, cols);

  while (true) {
    int ch = getch();
    if (ch == 'q') break;
    
    board.step();
    board.get_string(life_string);
    move(0, 0);
    addstr(life_string);
    refresh();
  }
  
  // restore terminal settings
  endwin();

  return 0;
}
