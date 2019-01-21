#include <string>
#include <iostream>
#include <fstream>

class Game {
    public:
    Game();
    void play();
    void printTurn();

    private:
    char c;
    int len;
    int seed;
    std::string word;
    std::string guess;
    void setword();
    bool invalidguess();
    bool inword();
};