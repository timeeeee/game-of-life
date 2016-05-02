#ifndef __LIFE_H__
#define __LIFE_H__

class Life {
 private:
  bool * board;
  unsigned int rows;
  unsigned int cols;
  unsigned int length;

 public:
  Life(unsigned int num_rows, unsigned int num_cols);
  ~Life();
  void clear();
  void get_string(char * string);
  void fpentamino();
  void random();
  void random(float r);
  void step();
};
  
#endif
