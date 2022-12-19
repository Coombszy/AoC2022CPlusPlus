#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <optional>
#include <tuple>
#include "rps.h"

using namespace std;

// Converts char move to enum
Move convert(const char& c_move) {
    
    switch (c_move) {
        case 'A':
            return rock;
        case 'B':
            return paper;
        case 'C':
            return scissors;
        case 'X':
            return rock;
        case 'Y':
            return paper;
        case 'Z':
            return scissors;
        default:
            cout << "FATAL: Failed to parse move char to enum! unknown move: " << c_move << endl;
            exit(1);
    }
}

// To draw, use the same move
Move get_draw(const Move& move) {
    return move;
}

// Returns correct move to win
Move get_win(const Move& move) {
    switch (move) {
        case rock:
            return paper;
        case paper:
            return scissors;
        case scissors:
            return rock;
    }
}

// Returns correct move to lose
Move get_loss(const Move& move) {
    switch (move) {
        case rock:
            return scissors;
        case paper:
            return rock;
        case scissors:
            return paper;
    }
}



// Converts single line string to tuple of moves (A single round)
tuple<Move, Move> get_round(const string& move_string) {
    return make_tuple(
            convert(move_string[0]),
            convert(move_string[2])
        );
}

// Reads contents of a file to produce rounds data
optional<vector<tuple<Move, Move>>> build_rounds_vec(const string& file_name) {
    
    ifstream file(file_name);

    if (!file.is_open()){
        cout << "Failed to open `" << file_name << "`" << endl;
        return {};
    }

    // move data
    vector<tuple<Move, Move>> rounds;

    // Read file contents and add moves to vector
    string line;
    while (std::getline(file, line)) {
        tuple<Move,Move> round_moves = get_round(line);
        rounds.push_back(round_moves);
    }

    return rounds;
}


