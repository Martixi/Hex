//
// Created by admin on 25.03.2024.
//

#ifndef HEX_DEFINES_H
#define HEX_DEFINES_H

#define BOARD_SIZE 8
#define PAWNS_NUMBER 11
#define IS 2
#define BOARD 5

struct position{
	int x;
	int y;
};

struct pawn{
	char color;
	position position;
};

struct board{
	int size = 0;
	int pawnsR = 0;
	int pawnsB = 0;
};

#endif //HEX_DEFINES_H

