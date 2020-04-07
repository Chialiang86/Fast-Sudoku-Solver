#include "sudoku.h"

int main() {
    Sudoku su_gene;
    int map[Sudoku::sudokuSize]= {
        0,0,0,5,0,8,0,0,3,
        8,0,0,7,0,0,4,0,6,
        0,5,7,0,0,4,0,8,1,
        0,0,0,2,0,6,0,3,0,
        0,7,0,0,5,0,6,0,0,
        5,0,2,0,3,0,0,4,0,
        0,0,1,6,0,5,0,0,9,
        2,8,0,1,0,9,0,0,0,
        6,9,4,0,0,0,7,1,5
    };
    su_gene.setMap(map);
    su_gene.generate();
    return 0;
}
