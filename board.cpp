//
// Created by admin on 25.03.2024.
//

#include "board.h"

char findPoint(int x, int y, pawn *pawns, board board){
	for (int i = 0; i < board.pawnsB + board.pawnsR; ++i) {
		if (pawns[i].position.x == x and pawns[i].position.y == y){
			if (pawns[i].color == 'r') return 'r';
			else return 'b';
		}
	}
	return ' ';
}

char **squareArray( board &board, pawn *pawns){

	//rotate board of size board.size and make it a two dimentional array
	char** ptr = new char*[board.size];
	for (int i = 0; i < board.size; ++i) {
		ptr[i] = new char[board.size];
	}
	//find pawns and place them in accurate place
	for (int i = 0; i < board.size; ++i) {
		for (int j = 0; j < board.size - i; ++j) {
			// cout << j << " " << i << "  ";
			ptr[j][i] = findPoint(i, j+i, pawns, board);
		}
		for (int j = 0; j < i; ++j) {
			// cout << board.size-i+j << " " << i << "  ";
			ptr[board.size-i+j][i] = findPoint(i - j - 1, board.size + j, pawns, board);
		}
		// cout << endl;
	}
	// cout << endl;
	return ptr;
}

char **boardConstructor(int &input, board &board, pawn *pawns){
	int size = 0, pawnX = 0, tmp = 0;
	board = {0, 0};

	while (input > 90 or input < 65){
		input = getchar();
		if (input == '<') pawnX++;
		else if (input == '\n') {
			size++;
			pawnX = 0;
		}else if (input == 'r') {
			board.pawnsR++;
			pawns[tmp] = {'r', pawnX -1 , size - 1};
			tmp++;
		}else if (input == 'b') {
			board.pawnsB++;
			pawns[tmp] = {'b', pawnX -1 , size - 1};
			tmp++;
		}
	}
	board.size = (size-1)/2;
	return squareArray(board, pawns);
}
