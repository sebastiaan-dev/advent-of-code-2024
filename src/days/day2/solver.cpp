//
// Created by Sebastiaan Gerritsen on 25/02/2025.
//

#include "solver.h"

#include <fstream>
#include <assert.h>
#include <iostream>
#include <list>
#include <map>
#include <sstream>

namespace day2 {

    Input Solver::readInput(std::string path) {
        std::ifstream file(path);

        assert(file.is_open());

        Input input;

        for (std::string line; std::getline(file, line);) {
            std::stringstream sline(line);
            std::vector<int> levels;

            for (std::string number; std::getline(sline, number, ' ');) {
                levels.push_back(std::stoi(number));
            }

            Report report = {.levels = levels};
            input.reports.push_back(report);
        }

        file.close();

        return input;
    }


    bool Solver::isPartOneValid() {
        input = readInput("src/days/day2/test.txt");
        const int count = solvePartOne();

        std::ifstream file("src/days/day2/test_answer_1.txt");
        assert(file.is_open());

        std::string line;
        std::getline(file, line);

        return std::stoi(line) == count;
    };

    bool Solver::isPartTwoValid() {
        input = readInput("src/days/day2/test.txt");
        const int count = solvePartTwo();

        std::ifstream file("src/days/day2/test_answer_2.txt");
        assert(file.is_open());

        std::string line;
        std::getline(file, line);

        return std::stoi(line) == count;
    };

    bool isTupleSafe(bool isIncreasing, int first, int second) {
        if (isIncreasing) {
            // If the next level has an equal or lower value it cannot be increasing,
            // stop checking.
            if (second <= first) {
                return false;
            }
        } else {
            if (second >= first) {
                return false;
            }
        }

        const int stepSize = abs(second - first);
        if (stepSize > 3 || stepSize < 1) {
            return false;
        }

        return true;
    }

    bool isReportSafe(Report report) {
        bool isSafe = true;
        bool isIncreasing = report.levels[0] < report.levels[1];

        for (int i = 1; i < report.levels.size(); ++i) {
            isSafe = isTupleSafe(isIncreasing, report.levels[i - 1], report.levels[i]);

            if (isSafe == false) {

                break;
            }
        }

        return isSafe;
    }

    int Solver::solvePartOne() {
        int safeCount = 0;

        for (const auto& report : input.reports) {
            assert(report.levels.size() >= 2);

            if (isReportSafe(report)) {
                safeCount++;
            }
        }

        return safeCount;
    }

    int Solver::solvePartTwo() {
        int safeCount = 0;

        for (const auto& report : input.reports) {
            assert(report.levels.size() >= 2);

            if (isReportSafe(report)) {
                safeCount++;
            } else {
                for (int i = 0; i < report.levels.size(); ++i) {
                    std::vector<int> lvl = report.levels;
                    lvl.erase(lvl.begin() + i);

                    if (isReportSafe({.levels = lvl})) {
                        safeCount++;
                        break;
                    }
                }
            }
        }

        return safeCount;
    }
}
