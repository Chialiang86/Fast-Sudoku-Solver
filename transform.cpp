#include "sudoku.h"

int main(int argc,char *argv[]) {
    int map[Sudoku::sudokuSize];
    Sudoku su_trans;
    for(int i=0; i<Sudoku::sudokuSize; ++i) {
        cin>>map[i];
    }
    su_trans.setMap(map);
    su_trans.transform();
    return 0;
}
