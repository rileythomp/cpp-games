#include <string>
#include <iostream>
#include "game.h"

using namespace std;

void print_welcome() {
    cout << endl;
    cout << "             Reversi             " << endl;
    cout << endl;
    cout << "Enter p to play" << endl;
    cout << "Enter i for instructions" << endl;
}

void print_instructions() {
    cout << endl;
    cout << "Reversi instructions" << endl;
    cout << "Game is played on an 8x8 grid" << endl;
    cout << "Players take turn placing their pieces on the board" << endl;
    cout << "Players must place their piece so that an opponents piece is between their" << endl;
    cout << "placed piece and another one of their own pieces (horizontally, vertically" << endl;
    cout << "and/or diagonally). Then, that opponent's piece is flipped over to become" << endl;
    cout << "one of the other players." << endl;
    cout << endl;
}

int main() {
    print_welcome();

    while (true) {
        string command;
        cin >> command;
        if (command == "p" || command == "P") {
            string p1_name;
            string p2_name;

            cout << "Player 1 name: ";
            cin >> p1_name;
            cout << "Player 2 name: ";
            cin >> p2_name;

            Game game = Game(p1_name, p2_name);;
            game.play();
        }
        else if  (command == "i" || command == "I") {
            print_instructions();
        }
        else if (command == "q" || command == "Q") {
            break;
        }
        cout << "Enter p to play again" << endl;
        cout << "Enter i for instructions" << endl;
        cout << "Enter q to quit" << endl;
    }

    cout << "Thanks for playing" << endl;

    return 0;
}