#include <string>
#include <vector>

class Player {
    public: 
    std::string name;
    std::vector<std::string> move_history;

        Player() {
            name = "";
            move_history = {};
        }

        Player(std::string _name) {
            name = _name;
            move_history = {};
        }
};