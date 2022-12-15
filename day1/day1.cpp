#include "elf.h"
#include <optional>
#include <algorithm>

using namespace std;
using namespace aoc;

int main()
{
    // DAY 1 Part 2
    //------------------------------------------------------------
    // Get the elf largest calorie count
    if (const auto elves = build_elves_vec("day1input.txt"); elves.has_value())
    {
        int largest = 0;

        for (const Elf& e : *elves) {
            if (e.totalCalories > largest) {
                largest = e.totalCalories;
            }
        }
        cout << "Day 1 Part 1" << endl;
        cout << "Highest calorie count is: " << largest << endl;
    }


    // DAY 1 Part 2
    //------------------------------------------------------------
    // Get the top 3 elves with the most calories

    // Clean elves
    if (const auto the_elves = build_elves_vec("day1input.txt"); the_elves.has_value())
    {
        vector<Elf> elves = *the_elves;

        sort(elves.begin(), elves.end(),
            [](const Elf& a, const Elf& b) {
                return (a.totalCalories > b.totalCalories);
            }
        );
        cout << "Day 1 Part 2" << endl;
        cout << "1. " << elves[0].totalCalories << endl;
        cout << "2. " << elves[1].totalCalories << endl;
        cout << "3. " << elves[2].totalCalories << endl;
        cout << "Total: " << elves[0].totalCalories + elves[1].totalCalories + elves[2].totalCalories << endl;
    }

    // Success
    return 0;
}
