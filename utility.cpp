//
// Created by admin on 25.03.2024.
//
#include "utility.h"
#include "queries.h"

using namespace std;

//skip unnecessary input
int skip(int &input){
	if (input == 'I'){
		for (int i = 0; i < IS; ++i) {
			cin.ignore();
		}
		input = getchar();
		if (input == 'G') return 'G';
		else{
			for (int i = 0; i < BOARD; ++i) {
				cin.ignore();
			}
			input = getchar();
		}
		if (input == 'C') return 'C';
		else {
				for (int i = 0; i < 7; ++i) {
					cin.ignore();
				}
				return 'P';
			}
		}
	return 0;
}

bool possibleNeighbour(Stack &stack, bool **visited, char **pawns, int x, int y, char type){
	if (pawns[y][x] == type and !visited[y][x]){
		stack.add(x, y);
		return true;
	}
	return false;
}

bool nextMove(Stack &stack, bool **visited, char **pawns, int size, char type){
	int x = stack.passX(), y = stack.passY(), helpx, helpy;
	int movement[6][2] = {{1, 1}, {0, 1}, {1, 0},
						  {-1, 0},{ 0, -1},{ -1, -1}};

	for (int i = 0; i < 6; ++i) {
		helpx = x+movement[i][0];
		helpy = y+movement[i][1];

		if (x+movement[i][0] < 0 or y+movement[i][1] < 0 or x+movement[i][0] >= size or y+movement[i][1] >= size) continue;
		visited[y][x] = true;
		if (possibleNeighbour(stack, visited, pawns, x+movement[i][0], y+movement[i][1], type)){
			return true;
		} else visited[ y+movement[i][1]][x+movement[i][0]] = true;
	}
	return false;
}

//
//
//

//check if red won the game
bool didRedWin(board board, char **pawns){

	bool **visited = new bool*[board.size];
	for (int i = 0; i < board.size; ++i) {
		visited[i] = new bool[board.size];
	}
	for (int i = 0; i < board.size; ++i) {
		for (int j = 0; j < board.size; ++j) {
			visited[i][j] = false;
		}
	}

	Stack stack;
	for (int j = 0; j < board.size; ++j) {
		if (pawns[j][0] == 'r'){
			stack.add(0, j);
			while (stack.getSize()){
				if (stack.passX() == board.size-1){
					for (int i = 0; i < board.size; ++i) {
						delete []visited[i];
					}
					delete []visited;
					return true;
				} else if (nextMove(stack, visited, pawns, board.size, 'r')) continue;
				else stack.remove();
			}
		}
	}

	for (int i = 0; i < board.size; ++i) {
		delete []visited[i];
	}
	delete []visited;

	return false;
}
//check if blue won the game
bool didBlueWin(board board, char **pawns){
	bool **visited = new bool*[board.size];
	for (int i = 0; i < board.size; ++i) {
		visited[i] = new bool[board.size];
	}
	for (int i = 0; i < board.size; ++i) {
		for (int j = 0; j < board.size; ++j) {
			visited[i][j] = false;
		}
	}

	Stack stack;
	for (int j = 0; j < board.size; ++j) {
		if (pawns[0][j] == 'b'){
			stack.add(j, 0);
			while (stack.getSize()){
				if (stack.passY() == board.size-1){
					for (int i = 0; i < board.size; ++i) {
						delete []visited[i];
					}
					delete []visited;
					return true;
				} else if (nextMove(stack, visited, pawns, board.size, 'b')) continue;
				else stack.remove();
			}
		}
	}
	for (int i = 0; i < board.size; ++i) {
		delete []visited[i];
	}
	delete []visited;
	return false;
}

//empty arrays for new use
void reset(char **pawnsPlacement, pawn* pawns){
	delete []pawns;
	delete pawnsPlacement;
}

bool multipleLines(board board, char **pawns, char type){
	bool win;
	for (int i = 0; i < board.size; ++i) {
		for (int j = 0; j < board.size; ++j) {
			if (pawns[i][j] == type) {
				pawns[i][j] = ' ';
				if (type == 'r') {
					win = didRedWin(board, pawns);
				} else {
					win = didBlueWin(board, pawns);
				}
				pawns[i][j] = type;
				if (!win) {
					return false;
				}
			}
		}
	}
	return true;
}


void boardCorrectCout(board board){
	if(isBoardCorrect(board)) {
		cout << "YES" << endl;
		return;
	} else cout << "NO" << endl;
}

char playerType(){
	char input, player;
	for (int i = 0; i < 2; ++i) {
		cin.ignore();
	}
	input = (char)getchar();
	if (input == 'R') {
		player = 'r';
		for (int i = 0; i < 10; ++i) {
			cin.ignore();
		}
	} else {
		player = 'b';
		for (int i = 0; i < 11; ++i) {
			cin.ignore();
		}
	}
	return player;
}

int getMoves(){
	int moves, skip;
	char input = (char)getchar();
	if (input == '1') moves = 1;
	else moves = 2;
	if (moves == 1) skip = 11;
	else skip = 12;
	for (int i = 0; i < skip; ++i) {
		cin.ignore();
	}

	return moves;
}

void message(bool function){
	if (function) cout << "YES" << endl;
	else cout << "NO" << endl;
}


bool isPathPossibleInN(board board, char **pawns, char player, int moves){
	for (int i = 0; i < board.size; ++i) {
		for (int j = 0; j < board.size; ++j) {
			if (pawns[i][j] == ' '){
				pawns[i][j] = player;
				if (moves > 1 and ((player == 'r' and didRedWin(board, pawns)) or (player == 'b' and didBlueWin(board, pawns)))) {
					pawns[i][j] = ' ';
					continue;
				}
				if (moves != 1){
					if (isPathPossibleInN(board, pawns, player, moves - 1)) {
						pawns[i][j] = ' ';
						return true;
					} else {
						pawns[i][j] = ' ';
						continue;
					}
				}
				if ((player == 'r' and didRedWin(board, pawns)) or (player == 'b' and didBlueWin(board, pawns))) {
					pawns[i][j] = ' ';
					return true;
				} else pawns[i][j] = ' ';
			}
		}
	}
	return false;
}

char nextMove(char currentPlayer){
	if (currentPlayer == 'r') return 'b';
	else return 'r';
}

bool isPathPossibleInP(board board, char whoStarts, char **pawns, char player, int movesP, int movesO){
	char movement = nextMove(whoStarts);
	if (movement == player){
		for (int i = 0; i < board.size; ++i) {
			for (int j = 0; j < board.size; ++j) {
				if (pawns[i][j] == ' ') {
					pawns[i][j] = player;
				}
				if (movesP > 1 and ((player == 'r' and didRedWin(board, pawns)) or (player == 'b' and didBlueWin(board, pawns)))) {
					pawns[i][j] = ' ';
					continue;
				}
				if (movesP != 1){
					if (isPathPossibleInP(board, movement, pawns, player, movesP - 1, movesO)) {
						pawns[i][j] = ' ';
						return true;
					} else {
						pawns[i][j] = ' ';
						continue;
					}
				}
				if ((player == 'r' and didRedWin(board, pawns)) or (player == 'b' and didBlueWin(board, pawns))) {
					pawns[i][j] = ' ';
					return true;
				} else {
					pawns[i][j] = ' ';
					return false;
				}
			}
		}
		return false;
	} else {
		for (int i = 0; i < board.size; ++i) {
			for (int j = 0; j < board.size; ++j) {
				if (pawns[i][j] == ' ') {
					pawns[i][j] = movement;
				}
				if (movesO > 1 and ((movement == 'r' and didRedWin(board, pawns)) or (movement == 'b' and didBlueWin(board, pawns)))) {
					pawns[i][j] = ' ';
					continue;
				}
				if ((movement == 'r' and didRedWin(board, pawns)) or (movement == 'b' and didBlueWin(board, pawns))) {
					pawns[i][j] = ' ';
					return false;
				}
				if (movesO != 1){
					if (!isPathPossibleInP(board, movement, pawns, player, movesP, movesO - 1)) {
						pawns[i][j] = ' ';
						return false;
					} else {
						pawns[i][j] = ' ';
						continue;
					}
				}
			}
		}
		return true;
	}
}