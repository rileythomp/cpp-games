#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

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
	cout << "_________________________" << endl;
	cout << "|                       |" << endl;
	cout << "|        Hangman        |" << endl;
	cout << "|_______________________|" << endl;
	cout << endl;         
	printHanger();
	cout << "Enter start the begin playing" << endl;
	cout << endl;
}

string getword(int n) {
	srand(n);
	ifstream words("words.txt");
	int random = rand()%7703;
	int numlines = 0;
	string line;
	string word;
	while (numlines <= random) {
		getline(words, line);
		if (numlines == n) {
			word = line;
			break;
		}
		numlines++;
	}
	return word;
}

bool inword(char c, string s) {
	for (auto i : s) {
		if (c == i) {return true;}
	}
	return false;
}

bool invalidguess(string s) {
	return s.length() != 1 || !isalpha(s[0]);
}

void printTurn(int n) {
	printHanger();
	For(i, n) {cout << "_ " ;}
	cout << endl << endl;
	cout << "Enter a guess: ";
}

int main() {
	printStart();
	string start;
	while (cin >> start) {
		cout << endl;
		if (start == "start") {
			cout << "Please enter a number: ";
			int n;
			cin >> n;
			string word = getword(n);
			int len = word.length();
			printTurn(len);
			string guess;
			while (cin >> guess) {
				if (invalidguess(guess)) {
					cout << "Please enter a valid guess: ";
					continue;
				}
				if (inword(guess[0], word)) {
					cout << "Correct, " << guess[0] << " is in the word" << endl;
				} else {
					cout << "Sorry, " << guess[0] << " is not in the word" << endl;
				}
				printTurn(len);
			}
		} else if (start == "exit") {
			cout << "Thanks for playing!" << endl;
			break;
		}
	}
}


