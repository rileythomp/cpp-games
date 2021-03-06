#include "game.h"
#include "title_print.h"

#define For(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

void printHanger() {
	cout << "  ___________" << endl;
	cout << "  |         |" << endl;
	cout << "  |          " << endl;
	cout << "  |          " << endl;
	cout << "  |          " << endl;
	cout << "  |          " << endl;
	cout << "  |          " << endl;
	cout << "  |          " << endl;
	cout << "__|__        " << endl;
	cout << endl;
}

void printStart() {
	//cout << "_________________________" << endl;
	//cout << "|                       |" << endl;
	//cout << "|        Hangman        |" << endl;
	//cout << "|_______________________|" << endl;
	//cout << endl;
	print_title("hangman");     
	printHanger();
	cout << "Enter start to begin playing" << endl;
	cout << endl;
}

int main() {
	printStart();
	string start;
	while (cin >> start) {
		cout << endl;
		if (start == "start") {
			Game g;
			g.printTurn();
			g.play();
		} else if (start == "exit") {
			cout << "Thanks for playing!" << endl << endl;
			break;
		}
		cout << "Enter start to play again or exit to quit" << endl << endl;
	}
}


