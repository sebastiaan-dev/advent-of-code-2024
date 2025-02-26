//
// Created by Sebastiaan Gerritsen on 25/02/2025.
//

#ifndef SOLVER_DAY3
#define SOLVER_DAY3
#include <vector>

#include "../../IDaySolver.h"

namespace day3 {
    struct Input {
        std::vector<std::vector<int>> multiplications;
    };

    class Solver: public IDaySolver {
    public:
        Solution solve() override {
            input = readInput("src/days/day3/input.txt");
            int partOne = solvePartOne();
            input = readInputV2("src/days/day3/input.txt");
            int partTwo = solvePartTwo();

            return Solution{.partOne = partOne, .partTwo = partTwo};
        }
    private:
        Input input;

        Input readInput(std::string path);
        Input readInputV2(std::string path);

        bool isPartOneValid() override;
        bool isPartTwoValid() override;

        int solvePartOne();
        int solvePartTwo();
    };
}



#endif //SOLVER_H
