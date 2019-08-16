#include <string>
#include <iostream>
#include "game.h"
#include "title_print.h"

using namespace std;


int main() {
    string user_input;
    print_title("chess");
    while (getline(cin, user_input)) {
        if (user_input == "setup") {
            string p1_name;
            getline(cin, p1_name);
            string p2_name;
            getline(cin, p2_name);

            Board board;
            Player p1(p1_name);
            Player p2(p2_name);

            Game game(board, p1, p2);
        }
    }
}
