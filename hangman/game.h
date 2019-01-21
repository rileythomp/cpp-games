#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

class Game {
    public:
    Game();
    void play();
    void printTurn();

    private:
    char c;
    int len;
    int seed;
    int wrong;
    std::string word;
    std::string guess;
    std::vector<char> guesses;
    std::vector<char> letters;
    bool haswon();
    bool inword();
    void setword();
    bool invalidguess();
    bool alreadyguessed();
};