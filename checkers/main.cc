#include "game.h"

#define For(n) for(int i = 0; i < (n); ++i)

using namespace std;

void printStart() {
	cout << " ____________________________" << endl;
	cout << "|                            |" << endl;
	cout << "|          Checkers          |" << endl;
	cout << "|____________________________|" << endl;
	cout << endl;
	cout << "Type start to begin a game!" << endl << endl;
}

int main() {
    printStart();
    string cmd;
    while (cin >> cmd) {
        if (cmd == "start") {Game game;} 
		else if (cmd == "quit") {break;} 
		else {cout << "Type new to start a game or quit to exit" << endl;}
    }
}