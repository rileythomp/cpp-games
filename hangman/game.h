#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

class Game {
    char c;
    int len;
    int seed;
    int wrong;
    std::string word;
    std::string guess;
    std::vector<char> guesses;
    std::vector<char> letters;
    void setword();
    bool haswon();
    bool inword();
    bool invalidguess();
    bool alreadyguessed();

    public:
    Game();
    void play();
    void printTurn();
};