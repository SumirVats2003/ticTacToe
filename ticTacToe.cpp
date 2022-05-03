#include <bits/stdc++.h>
using namespace std;

int xState[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int zState[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

void printBoard(int xState[], int zState[]) {
	char one = xState[0]?'X':(zState[0]?'O':'0');
	char two = xState[1]?'X':(zState[1]?'O':'1');
	char three = xState[2]?'X':(zState[2]?'O':'2');
	char four = xState[3]?'X':(zState[3]?'O':'3');
	char five = xState[4]?'X':(zState[4]?'O':'4');
	char six = xState[5]?'X':(zState[5]?'O':'5');
	char seven = xState[6]?'X':(zState[6]?'O':'6');
	char eight = xState[7]?'X':(zState[7]?'O':'7');
	char nine = xState[8]?'X':(zState[8]?'O':'8');
	cout << " " << one << " | " << two << " | " << three << "\n";
	cout << "---+---+---\n";
	cout << " " << four << " | " << five << " | " << six << "\n";
	cout << "---+---+---\n";
	cout << " " << seven << " | " << eight << " | " << nine << "\n";
}

int validateX(int x) {
	if(zState[x] == 1) {
		return 0;
	}
	return 1;
}

int validateZ(int z) {
	if(xState[z] == 1) {
		return 0;
	}
	return 1;
}

int checkWin(int xState[], int zState[]) {
	int wins[8][3] = {
		{0,1,2},
		{3,4,5},
		{6,7,8},
		{0,3,6},
		{1,4,7},
		{2,5,8},
		{0,4,8},
		{2,4,6}
	};
	for (int i=0; i<8; i++) {
		if (xState[wins[i][0]] + xState[wins[i][1]] + xState[wins[i][2]] == 3) {
			printBoard(xState, zState);
			cout << "X wins!\n";
			return 1;
		}
		if (zState[wins[i][0]] + zState[wins[i][1]] + zState[wins[i][2]] == 3) {
			printBoard(xState, zState);
			cout << "O wins!\n";
			return 0;
		}
	}
	return -1;
}

int main() {
	cout << "Welcome to Tic Tac Toe!\n";
	int chance = 1;
	int x, o;
	while(true) {
		printBoard(xState, zState);
		if(chance) {
			cout << "X's turn: ";
			loop1:
				cin >> x;
				if(validateX(x))
					xState[x] = 1;
				else {
					cout << "Invalid move, try again: ";
					goto loop1;
				}
		}
		else {
			cout << "O's turn: ";
			loop2:
				cin >> o;
				if(validateZ(o))
					zState[o] = 1;
				else {
					cout << "Invalid move, try again: ";
					goto loop2;
				}
		}
		if(checkWin(xState, zState) != -1) {
			break;
		}
		chance = !chance;
	}
	return 0;
}
