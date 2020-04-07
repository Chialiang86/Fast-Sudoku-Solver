Script started on Sat Mar 16 15:33:09 2019
[?1034hbash-3.2$ make

                  g++ -c solve.cpp

                  g++ -c sudoku.cpp

                  g++ -o solve solve.o sudoku.o

                  g++ -c transform.cpp

                  g++ -o transform transform.o sudoku.o

                  g++ -c generate.cpp

                  g++ -o generate generate.o sudoku.o

                  bash-3.2$ ./solve < solve.in

                  1
                  1 3 7 2 9 8 5 4 6
                  5 8 9 4 6 3 2 7 1
                  4 2 6 5 1 7 3 9 8
                  2 4 1 7 3 5 6 8 9
                  8 7 3 9 2 6 1 5 4
                  9 6 5 8 4 1 7 3 2
                  6 9 4 3 7 2 8 1 5
                  3 1 8 6 5 4 9 2 7
                  7 5 2 1 8 9 4 6 3

                  bash-3.2$ ./transform < transform.in

                  4 20
                  1 2 3
                  0 0 3 6 0 0 0 0 2
                  0 0 0 0 0 8 0 9 6
                  0 0 7 0 9 1 8 0 0
                  0 0 0 1 2 0 7 0 0
                  0 4 0 7 0 0 0 0 0
                  1 0 0 0 0 9 0 0 0
                  0 0 0 0 1 0 3 0 4
                  0 0 1 0 0 0 6 0 0
                  6 0 4 0 5 0 0 1 0


                  bash-3.2$ ./generate < solve.in

                  0 0 0 5 0 8 0 0 3
                  8 0 0 7 0 0 4 0 6
                  0 5 7 0 0 4 0 8 1
                  0 0 0 2 0 6 0 3 0
                  0 7 0 0 5 0 6 0 0
                  5 0 2 0 3 0 0 4 0
                  0 0 1 6 0 5 0 0 9
                  2 8 0 1 0 9 0 0 0
                  6 9 4 0 0 0 7 1 5


                  bash-3.2$ exit

                  Script done on Sat Mar 16 15:33:56 2019
# Fast-Sudoku-Solver
