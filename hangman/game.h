#include <string>
#include <iostream>
#include <fstream>

class Game {
    int len;
    int seed;
    char c;
    std::string guess;
    std::string word;
    void setword();
    bool inword(char c, std::string word);
    bool invalidguess(std::string s);
    bool invalidguess();
    bool inword();
    public:
    void printTurn();
    void play();
    Game();
};