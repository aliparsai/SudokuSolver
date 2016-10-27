//
// Created by perham on 10/27/16.
//

#include <iostream>
#include "SudokuSolver.h"

SudokuBoard *SudokuSolver::getBoard() const {
    return board;
}

void SudokuSolver::setBoard(SudokuBoard *board) {
    SudokuSolver::board = board;
}

SudokuSolver::SudokuSolver() {
    board = new SudokuBoard();
    counter = 0;
}

SudokuSolver::SudokuSolver(SudokuBoard *board) {
    this->board = board;
    counter = 0;
}

bool SudokuSolver::solver(int x, int y) {
    counter++;
    std::cout << "\r" << counter;
    std::cout.flush();
    int tmpNum;
    bool breakFlag = false;

    int i = 0, j = 0;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            tmpNum = board->getNum(i, j);
            if (tmpNum > 9 || tmpNum < 1) {
                breakFlag = true;
                break;
            }
        }
        if (breakFlag)
            break;
    }

    if (i == 9 && j == 9) {
        if (!board->checkIntegrity()) {
            board->delNum(x, y);
            return false;
        }
        else {
            return true;
        }
    }

    for (int num = 1; num <= 9; num++) {
        if (board->checkNum(num, i, j)) {
            board->setNum(num, i, j);
            if (solver(i, j)) {
                return true;
            }
            board->delNum(i, j);
        }

    }

    board->delNum(x, y);
    return false;

}
