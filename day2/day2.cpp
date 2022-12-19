#include <optional>
#include <tuple>
#include <vector>
#include <iostream>
#include "rps.h"

using namespace std;

// Returns score from a given round
int get_score_day1(const tuple<Move, Move>& round) {
    
    int score = 0;
    // o = opponent, p = player
    const auto& [o, p] = round;

    // Add score for using a particular move
    score += get<1>(round);

    // It's a draw!
    if (o == p) {
        score += 3;
    }
    // Player wins!
    // TODO: Ask matt about nicer formatting for this?
    else if ( 
            (o == rock && p == paper)
            || (o == paper && p == scissors)
            || (o == scissors && p == rock)
            ) {
        score += 6;
    }

    return score;

}

// Returns score from a given round
int get_score_day2(tuple<Move, Move>& round) {

    int score = 0;
    // o = opponent, p = player
    auto& [o, p] = round;

    // This is still kinda a hack, as we are not using
    // the enum for it's intended purpose. Instead of 
    // converting XYZ from the data in into another enum
    // that might contain how to end the round. We are converting
    // a move from part 1 into the end of the round state.

    // If X, need to lose (rock == 'X')
    if (p == rock) {
        p = get_loss(o);
    }
    // If Y, need to draw (paper == 'Y')
    else if (p == paper) {
        p = get_draw(o);
    }
    // If Z, need to lose (scissors == 'Z')
    else if (p == scissors) {
        p = get_win(o);
    }

    return get_score_day1(round);
}

int main()
{

    // DAY 2 Part 1
    //------------------------------------------------------------
    // Calculate score for player following guide

    // Run if day2input was loaded correctly
    if (const auto rounds = build_rounds_vec("day2input.txt"); rounds.has_value()) {
        int score = 0;
        // Add to score for each round
        for (const tuple<Move, Move>& r : *rounds) {
            score += get_score_day1(r);
        }

        // Final score!
        cout << "You scored (Day1): " << score << endl;
    }

    // DAY 2 Part 2
    //------------------------------------------------------------
    // Calculate score for player following elfs instructions

    // Run if day2input was loaded correctly
    if (auto rounds = build_rounds_vec("day2input.txt"); rounds.has_value()) {
        int score = 0;
        // Add to score for each round
        for (tuple<Move, Move>& r : *rounds) {
            score += get_score_day2(r);
        }

        // Final score!
        cout << "You scored (Day2): " << score << endl;
    }

    return 0;
}



