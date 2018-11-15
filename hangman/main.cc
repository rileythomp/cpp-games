#include <iostream>
#include <string>
#include "game.h"
using namespace std;

#define For(i,n) for(int i = 0; i < (n); ++i)

void printStart() {
	For(i, 38) {
		if (i != 0) {
			cout << '_';
		} else {
			cout << ' ';
		}
	}
	cout << endl << '|';
	For(i, 37) {cout << ' ';}
	cout << '|' << endl << '|';
	For(i, 15) {cout << " ";}
	cout << "Hangman";
  	For(i, 15) {cout << " ";}
	cout << '|' << endl << '|';
	For(i, 37) {cout << '_';}
	cout << '|' << endl << endl << "Type new to start a game!" << endl;
}

int main () {
  printStart();
  string cmd;
  while (cin >> cmd) {
	if (cmd == "new") {
		std::cout << "hi" << std::endl;
		Game g();
		cout << g.word  << endl;
	} else if (cmd == "quit") {
		cout << "Thanks for playing!" << endl;
		break;
	}
  }
  return 0;
}
