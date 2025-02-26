//
// Created by Sebastiaan Gerritsen on 25/02/2025.
//

#ifndef SOLVER_H
#define SOLVER_H
#include <vector>

#include "../../IDaySolver.h"

namespace day1 {
    struct Input {
        std::vector<int> leftList;
        std::vector<int> rightList;
    };

    class Solver: public IDaySolver {
    public:
        Solution solve() override {
            input = readInput("src/days/day1/input.txt");
            return Solution{.partOne = solvePartOne(), .partTwo = solvePartTwo()};
        }
    private:
        Input input;

        Input readInput(std::string path);

        bool isPartOneValid() override;
        bool isPartTwoValid() override;

        int solvePartOne();
        int solvePartTwo();
    };
}



#endif //SOLVER_H
