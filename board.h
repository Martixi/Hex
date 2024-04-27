//
// Created by admin on 25.03.2024.
//

#ifndef HEX_BOARD_H
#define HEX_BOARD_H
#include "defines.h"
#include "utility.h"
#include "iostream"


char **squareArray( board &board, pawn *pawns);


char **boardConstructor(int &input, board &board, pawn *pawns);
#endif //HEX_BOARD_H
