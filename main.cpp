#include <iostream>
#include "SudokuBoard.h"
#include "SudokuSolver.h"


using namespace std;

int main() {
    int p[9][9] = {{0, 0, 0, 0, 0, 0, 4, 5, 6},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 5, 0, 0, 4, 6, 0, 9, 2},
                   {2, 8, 0, 7, 0, 0, 0, 0, 3},
                   {6, 0, 0, 0, 1, 0, 5, 0, 0},
                   {0, 0, 0, 0, 0, 8, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 3, 0, 0},
                   {8, 0, 0, 9, 0, 4, 6, 0, 0},
                   {0, 2, 0, 8, 0, 0, 0, 0, 1}};

    SudokuBoard s(p);
    SudokuSolver sl(&s);

    sl.solver(-1,-1);

    sl.getBoard()->print();
    return 0;
}