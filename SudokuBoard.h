//
// Created by perham on 10/27/16.
//

#ifndef SUDOKUSOLVER_SUDOKUBOARD_H
#define SUDOKUSOLVER_SUDOKUBOARD_H


class SudokuBoard {
private:
    unsigned char place[9][9];

public:
    SudokuBoard();

    SudokuBoard(int p[9][9]);

    bool setNum(int num, int x, int y);

    bool checkNum(int num, int x, int y);

    bool delNum(int x, int y);

    int getNum(int x, int y);

    void print();

    bool checkIntegrity();

    SudokuBoard &operator=(SudokuBoard other);
};

#endif //SUDOKUSOLVER_SUDOKUBOARD_H
