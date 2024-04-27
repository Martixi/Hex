#include <iostream>
#include "queries.h"
#include "utility.h"

using namespace std;

//input commands
//todo: CAN_RED_WIN_IN_N_MOVE_WITH_PERFECT_OPPONENT (...)


void coutTableTmp(char **table, int size){
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int a, query;
	char **pawnsPlacement = nullptr;
	board board;
	pawn* pawns = new pawn [121];

	//perform till end of line found in input
	while ((a = getchar()) != EOF){
		if (a == '-') {
			reset(pawnsPlacement, pawns);
			pawns = new pawn [121];
			pawnsPlacement = boardConstructor(a, board, pawns);
			//coutTableTmp(pawnsPlacement, board.size);
		}

		//if query is right after board, first letter passed to 'a' element
		if (a == 'B') boardSize(board);
		else if (a == 'P') pawnsNumber(board);
		else if (a == 'C' and getchar() == 'A') canPlayerWin(board, pawnsPlacement);
		else if (a == 'I') {
			query = skip(a);
			//recognize what "Is..." query was assigned
			switch (query) {
				case 'G':
					isGameOver(board, pawnsPlacement);
					break;
				case 'C':
					boardCorrectCout(board);
					break;
				case 'P':
					message(isBoardPossible(board, pawnsPlacement));
					break;
				default:
					break;
			}
		}
	}

	//clean memory
	delete []pawns;
	delete pawnsPlacement;

	return 0;
}
