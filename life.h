#ifndef __LIFE_H__
#define __LIFE_H__

class Life {
 private:
  bool * board;
  unsigned char * neighbor_counts;
  unsigned int rows;
  unsigned int cols;
  unsigned int length;

 public:
  Life(unsigned int num_rows, unsigned int num_cols);
  ~Life();
  void clear();
  bool get(int row, int col);
  void set(int row, int col, bool value);
  void flip(int row, int col);
  void get_string(char * string);
  void fpentamino();
  void random();
  void random(float r);
  void step();
};
  
#endif
