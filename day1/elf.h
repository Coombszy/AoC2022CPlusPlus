#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <optional>

using namespace std;

namespace aoc
{
    struct Elf {
	    int totalCalories = 0;
    };

    // Reads contents of a file to produce elf data
    optional<vector<Elf>> build_elves_vec(const string& file_name) {
        
        // Day 1 input
        ifstream file(file_name);

        if (!file.is_open()){
            cout << "Failed to open `" << file_name << "`" << endl;
            return {};
        }

        // Elf data
        vector<Elf> elves;

        // Read file contents and add elves to vector
        string line;
        Elf a_elf; // Active elf
        while (std::getline(file, line)) {
            // New elf
            if (line == "") {
                elves.push_back(a_elf);
                a_elf = Elf();
            }
            // Same elf
            else {
                a_elf.totalCalories += stoi(line);
            }
        }

        return elves;
    }
}

