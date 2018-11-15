#include <string>
#include <iostream>
using namespace std;

#define For(i,n) for(int i = 0; i < (n); ++i)

void printWelcome() {
	For(i, 40) {
		if (i != 0) {
			cout << '_';
		} else {
			cout << ' ';
		}
	}
	cout << endl << '|';
	For(i, 39) {cout << ' ';}
	cout << '|' << endl << '|';
	For(i, 15) {cout << " ";}
	cout << "Connect 4";
  	For(i, 15) {cout << " ";}
	cout << '|' << endl << '|';
	For(i, 39) {cout << '_';}
	cout << '|' << endl << endl << "Type new to start a game!" << endl;
}


void printsubcell(char c) {
	cout << '|' << c << c << c;
}

void printsubrow(char c) {
	For(i, 7) {
        	printsubcell(c);
	}
	cout << '|';
	cout << endl;
}

void printrow() {
	printsubrow(' ');
	printsubrow(' ');
	printsubrow('_');
}

void printStart() {
	For(i, 6) {
		printrow();
	}
}

int main () {
  printWelcome();
  printStart(); 
  return 0;
}

