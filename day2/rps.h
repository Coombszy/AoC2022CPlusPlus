#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <optional>
#include <tuple>

using namespace std;

namespace aoc
{

    enum Move { rock, paper, scissors};

    // Reads contents of a file to produce move data
    optional<vector<tuple<Move, Move>>> build_moves_vec(const string& file_name) {
        
        ifstream file(file_name);

        if (!file.is_open()){
            cout << "Failed to open `" << file_name << "`" << endl;
            return {};
        }

        // move data
        vector<tuple<Move, Move>> moves;

        // Read file contents and add moves to vector
        string line;
        while (std::getline(file, line)) {
            // line.substr(0, )
            cout << line << endl;
        }

        return moves;
    }

    // Splits a string on spaces
    vector<tuple<Move, Move>> get_moves(string&) {


    }
}

