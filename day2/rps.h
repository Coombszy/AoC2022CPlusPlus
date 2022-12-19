#pragma once

#include <tuple>
#include <optional>
#include <vector>
#include <string>

using namespace std;

enum Move { rock = 1, paper = 2, scissors = 3};

// Returns all rounds from input data
optional<vector<tuple<Move, Move>>> build_rounds_vec(const string& file_name);

// Used for part 2 to get the correct move based on input
Move get_draw(const Move& move);
Move get_win(const Move& move);
Move get_loss(const Move& move);


