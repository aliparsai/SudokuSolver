//
// Created by perham on 10/27/16.
//

#ifndef SUDOKUSOLVER_SUDOKUSOLVER_H
#define SUDOKUSOLVER_SUDOKUSOLVER_H

#include "SudokuBoard.h"

class SudokuSolver {

private:
    SudokuBoard *board;
    uint64_t counter;

public:

    SudokuSolver(SudokuBoard *board);

    SudokuSolver();

    SudokuBoard *getBoard() const;

    void setBoard(SudokuBoard *board);

    bool solver(int x, int y);
};

#endif //SUDOKUSOLVER_SUDOKUSOLVER_H
