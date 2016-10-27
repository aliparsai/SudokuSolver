//
// Created by perham on 10/27/16.
//

#include <iostream>
#include "SudokuBoard.h"

SudokuBoard::SudokuBoard(int p[9][9]) {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            place[i][j] = ((p[i][j] <= 9 || p[i][j] > 0) ? p[i][j] : 99);
}

SudokuBoard::SudokuBoard() {

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            place[i][j] = 99;

}

bool SudokuBoard::setNum(int num, int x, int y) {

    bool status = checkNum(num, x, y);
    if (status)
        place[x][y] = num;

    return status;

}

bool SudokuBoard::checkNum(int num, int x, int y) {
    if (num > 9 || num < 1)
        return false;

    if (x > 8 || x < 0)
        return false;

    if (y > 8 || y < 0)
        return false;

    int i;

    for (i = 0; i < 9; i++)
        if (place[i][y] == num || place[x][i] == num ||
            place[(x - (x % 3) + i / 3)][(y - (y % 3) + i % 3)] == num)
            return false;

    return true;

}

int SudokuBoard::getNum(int x, int y) {
    if (x > 8 || x < 0)
        return 99;

    if (y > 8 || y < 0)
        return 99;

    return (int) place[x][y];

}

bool SudokuBoard::delNum(int x, int y) {
    if (x > 8 || x < 0)
        return false;

    if (y > 8 || y < 0)
        return false;

    place[x][y] = 99;
    return true;
}

bool SudokuBoard::checkIntegrity() {
    int num;

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            num = getNum(i, j);
            if (num <= 9 && num > 0) {
                delNum(i, j);
                if (!checkNum(num, i, j)) {
                    place[i][j] = num;
                    return false;
                }
                place[i][j] = num;
            }

        }

    return true;
}

void SudokuBoard::print() {
    std::cout << "\n-------------------------------\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0) std::cout << "|";
            std::cout << " " << (unsigned char) ((place[i][j] <= 9 && place[i][j] > 0) ? (place[i][j] + '0') : ' ') <<
            " ";

        }
        std::cout << "|\n";
        if (i % 3 == 2) std::cout << "-------------------------------\n";
    }

}

SudokuBoard &SudokuBoard::operator=(SudokuBoard other) {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            this->place[i][j] = other.place[i][j];

    return *this;
}
