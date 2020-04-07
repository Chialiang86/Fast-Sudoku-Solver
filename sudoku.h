#include <iostream>
#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <cstdlib>
using namespace std;

class Sudoku {
  public:
    Sudoku();
    Sudoku(const int init_map[]);
    void setMap(const int set_map[]);
    void generate();
    void transform();
    void reset();
    void solve(int,int);
    void printAns();
    void changeNum(int,int);
    void changeRow(int,int);
    void changeCol(int,int);
    void rotate(int);
    void mirror(int);
    void print(bool);
    void sortIndex();
    void setKey();
    void LegalNum(int,bool[]);
    int getElement(int);
    int cellKey();
    int noneZero();
    int getFirst();
    static const int sudokuSize = 81;

  private:
    int row_index,col_index,cell_index;
    bool boolmap[sudokuSize];
    int *zeroIndex;
    int map[sudokuSize];
    int row[sudokuSize];
    int col[sudokuSize];
    int cell[sudokuSize];
    int firstAns[sudokuSize];
    int ansNum;
    int n;
};
