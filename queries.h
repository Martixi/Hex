//
// Created by admin on 25.03.2024.
//

#ifndef HEX_QUERIES_H
#define HEX_QUERIES_H

#endif //HEX_QUERIES_H
#include "defines.h"
#include "iostream"
#include "board.h"

using namespace std;

void boardSize(board board);
void pawnsNumber(board board);
bool isBoardCorrect(board board);
void isGameOver(board board, char **pawns);
bool isBoardPossible(board board, char **pawns);
void canPlayerWin(board board, char **pawns);
bool naiveOponent(board board, char **pawns, char player, int moves);
bool perfectOponent(board board, char **pawns, char player, int moves);