#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "elf.h"

using namespace std;

// Reads contents of a file to produce elf data
vector<Elf> build_elves_vec(string file_name) {
    
    // Day 1 input
    ifstream file(file_name);

    if (!file.is_open()){
        cout << "Failed to open `" << file_name <<"`" << endl;
        exit(1);
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

int main()
{

    // DAY 1 Part 2
    //------------------------------------------------------------
    // Get the elf largest calorie count
    vector<Elf> elves = build_elves_vec("day1input.txt");
    int largest = 0;
    for (Elf e : elves) {
        if (e.totalCalories > largest) {
            largest = e.totalCalories;
        }
    }
    cout << "Day 1 Part 1" << endl;
    cout << "Highest calorie count is: " << largest << endl;


    // DAY 1 Part 2
    //------------------------------------------------------------
    // Get the top 3 elves with the most calories

    // Clean elves
    elves = build_elves_vec("day1input.txt");
    sort(elves.begin(), elves.end(),
        [](Elf& a, Elf&  b) {
            return (a.totalCalories > b.totalCalories);
        }
    );
    cout << "Day 1 Part 2" << endl;
    cout << "1. " << elves[0].totalCalories << endl;
    cout << "2. " << elves[1].totalCalories << endl;
    cout << "3. " << elves[2].totalCalories << endl;
    cout << "Total: " << elves[0].totalCalories + elves[1].totalCalories + elves[2].totalCalories << endl;

    // Success
    return 0;
}




