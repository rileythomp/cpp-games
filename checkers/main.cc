#include "game.h"
#include "title_print.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

void printStart() {
	// cout << " ____________________________" << endl;
	// cout << "|                            |" << endl;
	// cout << "|          Checkers          |" << endl;
	// cout << "|____________________________|" << endl;
	// cout << endl;
	print_title("checkers");
        cout << "Enter moves in the format 'AB,XY' where:" << endl;
        cout << "A is your starting column" << endl;
        cout << "B is your starting row" << endl;
        cout << "X is your ending coumn" << endl;
        cout << "Y is your ending row" << endl;
        cout << "Example: 05, 14" << endl;
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
