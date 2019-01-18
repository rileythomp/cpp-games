#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#define For(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

void printStart() {
	cout << "_________________________" << endl;
	cout << "|                       |" << endl;
	cout << "|        Hangman        |" << endl;
	cout << "|_______________________|" << endl;
	cout << endl;         
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
	cout << "Enter start the begin playing" << endl;
	cout << endl;
}

string getword(int n) {
	srand(n);
	ifstream words("words.txt");
	int rndm = rand()%7703;
	int numlines = 0;
	string line;
	string word;
	while (numlines <= rndm) {
		getline(words, line);
		if (numlines == n) {
			word = line;
			break;
		}
		numlines++;
	}
	return word;
}

int main() {
	printStart();

	string start;
	while (cin >> start) {
		if (start == "start") {
			cout << "Please enter a number: ";
			int n;
			cin >> n;
			string word = getword(n);
			int len = word.length();
			// print board
			// prompt guess

		} else if (start == "exit") {
			break;
		}
	}
}


