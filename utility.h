//
// Created by admin on 25.03.2024.
//

#ifndef HEX_UTILITY_H
#define HEX_UTILITY_H

#include "board.h"
#include "defines.h"
#include "iostream"
#include "stack.h"

using namespace std;


int skip(int &input);
bool didRedWin(board board, char **pawns);
bool didBlueWin(board board, char **pawns);
void reset(char **pawnsPlacement, pawn* pawns);
void boardCorrectCout(board board);
bool multipleLines(board board, char **pawns, char type);
char playerType();
int getMoves();
void message(bool function);
bool isPathPossibleInN(board board, char **pawns, char player, int moves);
bool isPathPossibleInP(board board, char whoStarts, char **pawns, char player, int movesP, int movesO);


#endif //HEX_UTILITY_H
