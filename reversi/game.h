
#ifndef GAME_H
#define GAME_H

#include <vector>
#include "cell.h"

class Game {
    typedef std::vector<Cell> Row;
    private:
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

        void print_row(Row row) {
            for (auto cell : row) {
                std::cout << "| " << cell.colour << " ";
            }
            std::cout << "|" << std::endl;;
        }

        void print_board() {
            std::cout << "    0   1   2   3   4   5   6   7  " << std::endl;
            std::cout << "   ___ ___ ___ ___ ___ ___ ___ ___ " << std::endl;
            int i = 0;
            for (auto row : board) {
                std::cout << "  |   |   |   |   |   |   |   |   |" << std::endl;    
                std::cout << i << " ";            
                print_row(row);
                std::cout << "  |___|___|___|___|___|___|___|___|" << std::endl;
                i += 1;
            }
        }

        inline bool invalid_move() {
            return row < 0 || row > 7 || col < 0 || col > 7 || !board.at(row).at(col).empty;
        }

        inline std::string current_player() {
            return turn ? p1_name : p2_name;
        }

        inline std::string player_colour() {
            return turn ? "W" : "B";
        }

        void get_moves() {
            // std::cout << current_player() << "'s turn" << std::endl;
            std::cout << player_colour() << "'s turn" << std::endl;
            std::cout << "Row: ";
            getline(std::cin, row_in);
            if (row_in == "quit") {
                throw std::runtime_error("Quit game");
            }
            std::cout << "val: " << row_in << std::endl;
            std::cout << "Column: ";
            getline(std::cin, col_in);
            if (col_in == "quit") {
                throw std::runtime_error("Quit game");
            }
            std::cout << "val: " << col_in << std::endl;
            row = stoi(row_in);
            col = stoi(col_in);

            if (invalid_move()) {
                std::cout << "Invalid move, try again" << std::endl;
                get_moves();
            }
        }

        void update_board() {
            std::string colour = player_colour();

            // going up (cur row down to initial row)
            if (row > 1) {
                int cur_row = row-1;
                Cell cur_cell = board.at(cur_row).at(col);
                while (cur_row > 0 && !cur_cell.empty && cur_cell.colour != colour) {
                    cur_row -= 1;
                    cur_cell = board.at(cur_row).at(col);
                }
                if (cur_cell.colour == colour) {
                    for (int i = cur_row+1; i < row; ++i) {
                        board.at(i).at(col).colour = colour;
                    }
                }
            }

            // going down (initial row down to cur row)
            if (row < 6) {
                int cur_row = row+1;
                Cell cur_cell = board.at(cur_row).at(col);
                while (cur_row < 7 && !cur_cell.empty && cur_cell.colour != colour) {
                    cur_row += 1;
                    cur_cell = board.at(cur_row).at(col);
                }
                if (cur_cell.colour == colour) {
                    for (int i = row+1; i < cur_row; ++i) {
                        board.at(i).at(col).colour = colour;
                    }
                }
            }

            // going left (start at cur col, go to initial col)
            if (col > 1) {
                int cur_col = col-1;
                Cell cur_cell = board.at(row).at(cur_col);
                while (cur_col > 0 && !cur_cell.empty && cur_cell.colour != colour) {
                    cur_col -= 1;
                    cur_cell = board.at(row).at(cur_col);
                }
                if (cur_cell.colour == colour) {
                    for (int i = cur_col+1; i < col; ++i) {
                        board.at(row).at(i).colour = colour;
                    }
                }
            }

            // going right (start at initial col, go to cur col)
            if (col < 6) {
                int cur_col = col+1;
                Cell cur_cell = board.at(row).at(cur_col);
                while (cur_col < 7 && !cur_cell.empty && cur_cell.colour != colour) {
                    cur_col += 1;
                    cur_cell = board.at(row).at(cur_col);
                }
                if (cur_cell.colour == colour) {
                    for (int i = col+1; i < cur_col; ++i) {
                        board.at(row).at(i).colour = colour;
                    }
                }
            }

            if (row > 1 && col > 1) {
                int cur_row = row-1;
                int cur_col = col-1;
                Cell cur_cell = board.at(cur_row).at(cur_col);
                while (cur_col > 0 && cur_row > 0 && !cur_cell.empty && cur_cell.colour != colour) {
                    cur_row -= 1;
                    cur_col -= 1;
                    cur_cell = board.at(cur_row).at(cur_col);
                }
                if (cur_cell.colour == colour) {
                    for (int i = cur_row+1, j = cur_col+1; i < row, j < col; ++i, ++j) {
                        board.at(i).at(j).colour = colour;
                    }
                }
            }

            if (row < 6 && col < 6) {
                int cur_row = row+1;
                int cur_col = col+1;
                Cell cur_cell = board.at(cur_row).at(cur_col);
                while (cur_col < 7 && cur_row < 7 && !cur_cell.empty && cur_cell.colour != colour) {
                    cur_row += 1;
                    cur_col += 1;
                    cur_cell = board.at(cur_row).at(cur_col);
                }
                if (cur_cell.colour == colour) {
                    for (int i = row+1, j = col+1; i < cur_row, j < cur_col; ++i, ++j) {
                        board.at(i).at(j).colour = colour;
                    }
                }
            }

            if (row > 1 && col < 6) {
                int cur_row = row-1;
                int cur_col = col+1;
                Cell cur_cell = board.at(cur_row).at(cur_col);
                while (cur_col < 7 && cur_row > 0 && !cur_cell.empty && cur_cell.colour != colour) {
                    cur_row -= 1;
                    cur_col += 1;
                    cur_cell = board.at(cur_row).at(cur_col);
                }
                if (cur_cell.colour == colour) {
                    for (int i = cur_row+1, j = cur_col-1; i < row, j > col; ++i, --j) {
                        board.at(i).at(j).colour = colour;
                    }
                }
            }

            if (row < 6 && col > 1) {
                int cur_row = row+1;
                int cur_col = col-1;
                Cell cur_cell = board.at(cur_row).at(cur_col);
                while (cur_col > 0 && cur_row < 7 && !cur_cell.empty && cur_cell.colour != colour) {
                    cur_row += 1;
                    cur_col -= 1;
                    cur_cell = board.at(cur_row).at(cur_col);
                }
                if (cur_cell.colour == colour) {
                    for (int i = row+1, j = col-1; i < cur_row, j > cur_col; ++i, --j) {
                        board.at(i).at(j).colour = colour;
                    }
                }
            }
        }

        void apply_moves() {
            board.at(row).at(col).colour = player_colour();
            board.at(row).at(col).empty = false;
            update_board();
            pieces_played += 1;
            turn = !turn;
        }

        inline void check_game_over() {
            if (pieces_played >= num_cells) {
                game_over = true;
            }
        }

        void winner_message() {
            int white_pieces = 0;
            for (auto row : board) {
                for (auto cell : row) {
                    if (cell.colour == "W") {
                        white_pieces += 1;
                    }
                }
            }
            int black_pieces = num_cells - white_pieces;
            print_board();
            std::cout << "whites: " << white_pieces << std::endl;
            if (white_pieces > black_pieces) {
                std::cout << p1_name << " wins" << std::endl;
            }
            else if (black_pieces > white_pieces) {
                std::cout << p2_name << " wins" << std::endl;
            }
            else {
                std::cout << "Tie game" << std::endl;
            }
        }

    public:
        Game(std::string _p1_name, std::string _p2_name) {
            pieces_played = 4;
            turn = true;
            game_over = false;
            p1_name = _p1_name;
            p2_name = _p2_name;
            for (int i = 0; i < board_len; ++i) {
                std::vector<Cell> row;
                for (int j = 0; j < board_len; ++j) {
                    if ((i == 3 && j == 3) || (i == 4 && j == 4)) {
                        row.emplace_back(Cell("W"));
                    }
                    else if ((i == 3 && j == 4) || (i == 4 && j == 3)) {
                        row.emplace_back(Cell("B"));
                    }
                    else {
                        row.emplace_back(Cell());
                    }
                }
                board.emplace_back(row);
            }
        }

        void play() {
            try {
                getline(std::cin, row_in);
                while (!game_over) {
                    print_board();

                    get_moves();

                    apply_moves();

                    check_game_over();
                }
                winner_message();
            }
            catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
            }
        }
};

#endif