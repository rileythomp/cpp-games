#include "game.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

void printStart() {
	cout << " ____________________________" << endl;
	cout << "|                            |" << endl;
	cout << "|          Checkers          |" << endl;
	cout << "|____________________________|" << endl;
	cout << endl;
	cout << "Type new to start a game" << endl << endl;
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