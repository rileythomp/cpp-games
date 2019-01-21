#include "game.h"

#define For(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

Game::Game() {
    cout << "Please enter a number: ";
	cin >> seed;
    setword();
}

void Game::setword() {
	srand(seed);
	ifstream words("words.txt");
	int random = rand()%7703;
	int numlines = 0;
	string line;
	while (numlines < random) {
		getline(words, line);
		numlines++;
	}
    word = line;
    len = word.length();
}

void Game::printTurn() {
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
	For(i, len) {cout << "_ " ;}
	cout << endl << endl;
	cout << "Enter a guess: ";
}

bool Game::invalidguess() {
	return guess.length() != 1 || !isalpha(guess[0]);
}

bool Game::inword() {
	for (auto i : word) {
		if (c == i) {return true;}
	}
	return false;
}


void Game::play() {
    while (cin >> guess) {
        if (invalidguess()) {
            cout << "Please enter a valid guess: ";
            continue;
        } else {
            c = guess[0];
        }
        if (inword()) {
            cout << "Correct, " << c << " is in the word" << endl;
        } else {
            cout << "Sorry, " << c << " is not in the word" << endl;
        }
        printTurn();
    }
}
