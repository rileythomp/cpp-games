
#ifndef GAME_H
#define GAME_H

#include <vector>
#include "cell.h"
// #include "window.h"
// #include "graphics.h"

class Game {
    public:
    Game(std::string _p1_name, std::string _p2_name);
    void play();

    private:
    typedef std::vector<Cell> Row;
    
    const int board_len = 8;
    const int num_cells = board_len*board_len;
    int pieces_played;
    std::string row_in;
    std::string col_in;
    int row;
    int col;
    bool turn;
    bool game_over;
    std::string p1_name;
    std::string p2_name;
    std::vector<Row> board;
    // Xwindow* xw = nullptr;
    // Graphics* screen1;
    // Graphics* screen2;


    void print_row(Row row);
    void print_board();
    inline bool invalid_move();
    void handle_bad_moves();
    inline std::string current_player();
    inline std::string player_colour();
    void get_moves();
    void update_board();
    void apply_moves();
    inline void check_game_over();
    void winner_message();
};

#endif