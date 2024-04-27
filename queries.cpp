//
// Created by admin on 25.03.2024.
//

#include "queries.h"


void boardSize(board board) {
	for (int i = 0; i < BOARD_SIZE; ++i) {
		cin.ignore();
	}
	cout << board.size << endl;
}

void pawnsNumber(board board) {
	for (int i = 0; i < PAWNS_NUMBER; ++i) {
		cin.ignore();
	}
	cout << board.pawnsB + board.pawnsR << endl;
}

bool isBoardCorrect(board board) {
	int a = board.pawnsR, b = board.pawnsB, difference = a - b;
	if (difference == 0 or difference == 1) {
		return true;
	} else {
		return false;
	}
}

void isGameOver(board board, char **pawns) {
	//impossible to win with so little pawns or incorrect board
	if ((board.pawnsR < board.size and board.pawnsB < board.size) or !isBoardCorrect(board)) {
		cout << "NO" << endl;
		return;
	} else if (didRedWin(board, pawns)) {
		cout << "YES RED" << endl;

		return;
	} else {
		if (didBlueWin(board, pawns)) {
			cout << "YES BLUE" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

bool isBoardPossible(board board, char **pawns) {
	bool winR, winB;
	if (!isBoardCorrect(board)) {
		return false;
	}

	if (board.size == 1) {
		return true;
	}

	winR = didRedWin(board, pawns);
	winB = didBlueWin(board, pawns);

	if (winR and winB) {
		return false;
	}

	if (!winR and !winB) {
		return true;
	}

	if (winR and board.pawnsB >= board.pawnsR) {
		return false;
	}

	if (winB and board.pawnsR != board.pawnsB) {
		return false;
	}
	if (winR) {
		if (multipleLines(board, pawns, 'r')) {
			return false;
		}
	}
	if (winB) {
		if (multipleLines(board, pawns, 'b')) {
			return false;
		}
	}
	return true;
}

void canPlayerWin(board board, char **pawns) {
	char input, player;
	int moves;
	player = playerType();
	moves = getMoves();
	input = (char) getchar();
	if ((input == 'N' and naiveOponent(board, pawns, player, moves)) or
	    (input == 'P' and perfectOponent(board, pawns, player, moves))) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

bool naiveOponent(board board, char **pawns, char player, int moves) {
	int emptySlots, count = 0;
	for (int i = 0; i < 12; ++i) {
		cin.ignore();
	}
	if (!isBoardPossible(board, pawns)) return false;
	if (didRedWin(board, pawns) or didBlueWin(board, pawns)) return false;

	if (player == 'r') {
		if (board.pawnsR == board.pawnsB) {
			if (moves == 1) emptySlots = 1;
			else emptySlots = 3;
		} else {
			if (moves == 1) emptySlots = 2;
			else emptySlots = 4;
		}
	} else {
		if (board.pawnsR == board.pawnsB) {
			if (moves == 1) emptySlots = 2;
			else emptySlots = 4;
		} else {
			if (moves == 1) emptySlots = 1;
			else emptySlots = 3;
		}
	}

	for (int i = 0; i < board.size; ++i) {
		for (int j = 0; j < board.size; ++j) {
			if (pawns[i][j] == ' ') count++;
		}
	}
	if (count < emptySlots) return false;
	return isPathPossibleInN(board, pawns, player, moves);


}

bool perfectOponent(board board, char **pawns, char player, int moves) {
	int emptySlots, count = 0, movesO;
	char first;
	for (int i = 0; i < 15; ++i) {
		cin.ignore();
	}
	if (!isBoardPossible(board, pawns)) return false;
	if (didRedWin(board, pawns) or didBlueWin(board, pawns)) return false;
	if (player == 'r') {
		if (board.pawnsR == board.pawnsB) {
			first = 'b';
			if (moves == 1) emptySlots = 1, movesO = 0;
			else emptySlots = 3, movesO = 1;
		} else {
			first = 'r';
			if (moves == 1) emptySlots = 2, movesO = 1;
			else emptySlots = 4, movesO = 2;
		}
	} else {
		if (board.pawnsR == board.pawnsB) {
			first = 'b';
			if (moves == 1) emptySlots = 2, movesO = 1;
			else emptySlots = 4, movesO = 2;
		} else {
			first = 'r';
			if (moves == 1) emptySlots = 1, movesO = 0;
			else emptySlots = 3, movesO = 1;
		}
	}

	for (int i = 0; i < board.size; ++i) {
		for (int j = 0; j < board.size; ++j) {
			if (pawns[i][j] == ' ') count++;
		}
	}
	if (count < emptySlots) return false;
	return isPathPossibleInP(board,first, pawns, player, moves, movesO);

}
