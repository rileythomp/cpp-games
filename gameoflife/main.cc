#include <string>
#include <iostream>
#include <vector>
#include <thread>        
#include <chrono>        
using namespace std;

#define For(i, n) for(int i = 0; i < (n); ++i)
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

void printStart() {
	For(i, 42) {
		if (i != 0) {
			cout << '_';
		} else {
			cout << ' ';
		}
	}
	cout << endl << '|';
	For(i, 41) {cout << ' ';}
	cout << '|' << endl << '|';
	For(i, 10) {cout << " ";}
	cout << "Conway's Game of Life";
  	For(i, 10) {cout << " ";}
	cout << '|' << endl << '|';
	For(i, 41) {cout << '_';}
	cout << '|' << endl << endl;
}

void print(vector<vector<int>> grid) {
    for (auto row : grid) {
        for (auto cell : row) {
            if (cell) {
		        cout << BOLDYELLOW << "\u25A0" << RESET << "  ";
	        } else {
	    	    cout << BOLDBLUE << "\u25A0" << RESET << "  ";
	        }
        }
        cout << endl;
    }
    cout << endl << endl;
}

vector<vector<int>> update(vector<vector<int>> grid) {
    vector<vector<int>> newGrid(40, vector<int>(40));
    int neighbourCount = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid.size(); ++j) {
            if (i > 0 && j > 0 && grid[i-1][j-1]) neighbourCount++;
            if (i > 0 && grid[i-1][j]) neighbourCount++;
            if (i > 0 && j < grid.size()-1 && grid[i-1][j+1]) neighbourCount++;
            if (j > 0 && grid[i][j-1]) neighbourCount++;
            if (j < grid.size()-1 && grid[i][j+1]) neighbourCount++;
            if (i < grid.size()-1 && j > 0 && grid[i+1][j-1]) neighbourCount++;
            if (i < grid.size()-1 && grid[i+1][j]) neighbourCount++;
            if (i < grid.size()-1 && j < grid.size()-1 && grid[i+1][j+1]) neighbourCount++;
            if (grid[i][j]) {
                if (neighbourCount < 2 || neighbourCount > 3) {
                    newGrid[i][j] = 0;
                } else {
                    newGrid[i][j] = 1;
                }
            } else if (neighbourCount == 3) {
                newGrid[i][j] = 1;
            }
            neighbourCount = 0;
        }
    }
    return newGrid;
}

int main() {
    vector<vector<int>> grid(40, vector<int>(40));
    // r pentomino
    grid[20][20] = 1;
    grid[19][20] = 1;
    grid[19][21] = 1;
    grid[21][20] = 1;
    grid[20][19] = 1;
    // acorn
    // grid[20][20] = 1;
    // grid[19][18] = 1;
    // grid[21][17] = 1;
    // grid[21][18] = 1;
    // grid[21][21] = 1;
    // grid[21][22] = 1;
    // grid[21][23] = 1;
    // b heptomino
    // grid[20][20] = 1;
    // grid[21][20] = 1;
    // grid[20][19] = 1;
    // grid[20][21] = 1;
    // grid[19][19] = 1;
    // grid[19][21] = 1;
    // grid[19][22] = 1;
    // pi heptomino
    // grid[19][20] = 1;
    // grid[19][18] = 1;
    // grid[19][21] = 1;
    // grid[20][19] = 1;
    // grid[20][21] = 1;
    // grid[21][21] = 1;
    // grid[21][19] = 1;
    // f heptomino
    // grid[20][20] = 1;
    // grid[19][20] = 1;
    // grid[21][20] = 1;
    // grid[22][20] = 1;
    // grid[19][19] = 1;
    // grid[22][21] = 1;
    // grid[22][22] = 1;
    printStart();
    while (1) {
        print(grid);
        grid = update(grid);
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    return 0;
}