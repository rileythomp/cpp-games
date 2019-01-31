#include "game.hh"
#include <sstream>

#define For(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

void Game::printBoard() {
    cout << "  13 14 15 16 17 18       19 20 21 22 23 24  " << endl;
    cout << " ___________________________________________ " << endl;
    cout << "|                   |   |                   |" << endl;
    For(i, 10) {
        if (i == 5) {
            cout << "|                   |BAR|                   |" << endl;
            continue;
        }
        cout << "|  ";
        For(j, 40) {
            if (j%3 == 0) {
                if (i < 5) {
                    int pointNum = j/3 + 13;
                    Point point = board[pointNum];
                    if (point.length >= i+1) { cout << point.letter(); }
                    else { cout <<  ' ';}
                }
                if (i > 5) {
                    cout << ' ';
                }
            } else {
                cout << ' ';
            }
        }
        cout << " |";
        cout << endl;
    }
    cout << "|___________________|___|___________________|" << endl;
	cout << "  12 11 10  9  8  7        6  5  4  3  2  1  " << endl;
}

Game::Game() {
    For(i, 24) {
        if (i == 1) { board.push_back(Point(2, 'x')); }
        else if (i == 6) { board.push_back(Point(5, 'o')); }
        else if (i == 8) { board.push_back(Point(3, 'o')); }
        else if (i == 12) { board.push_back(Point(5, 'x')); }
        else if (i == 13) { board.push_back(Point(5, 'o')); }
        else if (i == 17) { board.push_back(Point(3, 'x')); }
        else if (i == 19) { board.push_back(Point(5, 'x')); }
        else if (i == 24) { board.push_back(Point(2, 'o')); }
        else { board.push_back(Point()); }
    }
    turn = true;
    xLeft = 15;
    oLeft = 15;
    play();
}

bool isnum(string s) {
    for (auto i : s) { if (!isdigit(i)) { return false; } }
    return true;
}

bool Game::validMove() {
    if (roll1 == roll2 && movelist.size() != 4) {return false;}
    else if (roll1 != roll2 && movelist.size() != 2) {return false;}

    for (auto move : movelist) {
        string::size_type pos = move.find('/');
        if (pos != string::npos) { 
            string startmove = move.substr(0, pos); 
            string endmove = move.substr(pos+1);

            if (!isnum(startmove) || !isnum(endmove)) { return false; }

            int start = stoi(startmove);
            int end = stoi(endmove);

            if (start < 1 || start > 24 || end < 1 || end > 24) { return false; }
        }
        else { return false; }
    }
    return true;
}

bool Game::canMove() {
    for (auto move : movelist) {
        int start = stoi(move.substr(0, move.find('/')));
        int end = stoi(move.substr(move.find('/')+1));

        if (turn ? start <= end : start >= end) { return false; }
        Point startPoint = board[start];

        if (!startPoint.occupied) { return false; }

        if (startPoint.letter() != (turn ? 'x' : 'o')) { return false; }

        Point endPoint = board[end];
        if (endPoint.ownedBy() == (turn ? 'o' : 'x')) { return false; }
    }
    return true;
}

void Game::update() {
    movelist = {};
    printBoard();
}

bool Game::hasWinner() {
    return false;
}

void Game::getRolls() {
    while (1) {
        cout << "Enter roll to roll the dice: ";
        string proll;
        cin >> proll;

        if (proll != "roll") {continue;}

        roll1 = rand()%6 + 1;
        roll2 = rand()%6 + 1;

        if (roll1 == roll2) {cout << "You rolled double " << roll1 << "'s!" << endl;}
        else {cout << "You rolled a " << roll1 << " and a " << roll2 << endl;}
        break;
    }
}

void Game::getMoves() {
    while (1) {
        cout << "Enter your moves: ";
        string moves;
        cin.ignore();
        getline(cin, moves);

        stringstream movestream(moves);
        string move;
        while (movestream >> move) {
            movelist.push_back(move);
        }

        if (!validMove() || !canMove()) {
            cout << "Please enter a valid move" << endl;
            movelist = {};
        }
        else { break; }
    }
}

void Game::play() {
    time_t seedtime = time(nullptr);
    srand(seedtime);
    while (1) {
        getRolls();

        getMoves();

        update();

        if (hasWinner()) {
            cout << (turn ? 'o' : 'x') << " wins!" << endl;
            break;
        }
    }
}