#include "sudoku.h"
#include "Clock.h"
using namespace std;

int main() {
    Sudoku su_sol;
    Sudoku a=su_sol;
    Clock t;
    t.start();
    int first_index,num_is_filled,map[Sudoku::sudokuSize];
    for(int index=0; index<Sudoku::sudokuSize; ++index)
        cin>>map[index];//by app < file
    su_sol.setMap(map);
    num_is_filled=su_sol.noneZero();
    first_index=su_sol.getFirst();
    su_sol.setKey();
    su_sol.sortIndex();
    su_sol.solve(first_index,num_is_filled);
    su_sol.printAns();
    cout<<t.getElapsedTime()<<endl;
    return 0;
}
