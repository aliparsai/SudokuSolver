#include <iostream>
#include "SudokuBoard.h"
#include "SudokuSolver.h"


using namespace std;

int main() {

    int hardest[9][9] = {{0, 0, 0, 7, 0, 0, 0, 0, 0},
                         {1, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 4, 3, 0, 2, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 6},
                         {0, 0, 0, 5, 0, 9, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 4, 1, 8},
                         {0, 0, 0, 0, 8, 1, 0, 0, 0},
                         {0, 0, 2, 0, 0, 0, 0, 5, 0},
                         {0, 4, 0, 0, 0, 0, 3, 0, 0}};

    SudokuBoard s(hardest);
    SudokuSolver sl(&s);
    s.print();
    sl.solver(-1,-1);
    sl.getBoard()->print();

    return 0;
}
