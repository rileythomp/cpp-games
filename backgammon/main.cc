#include "game.h"

using namespace std;

void printBoard() {
	cout << "  13 14 15 16 17 18       19 20 21 22 23 24  " << endl;
	cout << " ___________________________________________ " << endl;
	cout << "|                   |   |                   |" << endl;
	cout << "|                   |   |                   |" << endl;
	cout << "|                   |   |                   |" << endl;
	cout << "|                   |   |                   |" << endl;
	cout << "|                   |BAR|                   |" << endl;
	cout << "|                   |   |                   |" << endl;
	cout << "|                   |   |                   |" << endl;
	cout << "|                   |   |                   |" << endl;
	cout << "|                   |   |                   |" << endl;
	cout << "|___________________|___|___________________|" << endl;
	cout << "  12 11 10  9  8  7        6  5  4  3  2  1  " << endl;   
}

void printStart() {
	cout << " ______________________________" << endl;
	cout << "|                              |" << endl;
	cout << "|          Backgammon          |" << endl;
	cout << "|______________________________|" << endl;
	cout << endl;
	cout << "Type new to start a game" << endl << endl;
	printBoard();
}

int main() {
    printStart();
    string cmd;
    while (cin >> cmd) {
        if (cmd == "new") {Game game;} 
		else if (cmd == "quit") {break;} 
		cout << "Type new to start a game or quit to exit" << endl;
    }
}