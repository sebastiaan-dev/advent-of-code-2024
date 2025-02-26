//
// Created by Sebastiaan Gerritsen on 25/02/2025.
//

#ifndef SOLVER_DAY2
#define SOLVER_DAY2
#include <vector>

#include "../../IDaySolver.h"

namespace day2 {
    struct Report {
        std::vector<int> levels;
    };

    struct Input {
        std::vector<Report> reports;
    };

    class Solver: public IDaySolver {
    public:
        Solution solve() override {
            input = readInput("src/days/day2/input.txt");
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
