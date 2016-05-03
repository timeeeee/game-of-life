#include <ncurses.h>

#include "life.h"

int main() {
  // initialize ncurses screen
  initscr();

  // disable tty char buffering to get one character at a time
  cbreak();

  // don't echo typed characters
  noecho();

  // Don't wait if a character isn't pressing a key
  nodelay(stdscr, TRUE);

  // enable capture of special keys
  keypad(stdscr, TRUE);

  // do fun stuff here
  int scr_rows, scr_cols;
  getmaxyx(stdscr, scr_rows, scr_cols);

  int life_rows = scr_rows - 1;
  int life_cols = scr_cols;

  char *life_string;
  life_string = new char[life_rows * life_cols];
  Life board(life_rows, life_cols);

  bool quit = false;
  bool play = false;

  int input_char = 0;

  while (!quit) {
    input_char = getch();
    switch (input_char) {
    case 'q':
      quit = true;
      break;
    case 'r':
      board.random();
      break;
    case 'f':
      board.fpentamino();
      break;
    case 'p':
      play = !play;
      break;
    }
    
    if (play) {
      board.step();
    }

    board.get_string(life_string);
    move(0, 0);
    addstr(life_string);
    refresh();
  }
  
  // Delete life_string
  delete[] life_string;

  // restore terminal settings
  endwin();

  return 0;
}
