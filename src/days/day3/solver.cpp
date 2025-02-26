//
// Created by Sebastiaan Gerritsen on 25/02/2025.
//

#include "solver.h"

#include <fstream>
#include <assert.h>
#include <iostream>
#include <list>
#include <map>
#include <regex>

namespace day3 {
    Input Solver::readInput(std::string path) {
        std::ifstream file(path);

        assert(file.is_open());

        Input input;
        std::regex mulRegex("mul\\([0-9]+,[0-9]+\\)");
        std::regex numberRegex("[0-9]+");

        for (std::string line; std::getline(file, line);) {
            auto wordsBegin = std::sregex_iterator(line.begin(), line.end(), mulRegex);
            auto wordsEnd = std::sregex_iterator();

            for (std::sregex_iterator i = wordsBegin; i != wordsEnd; ++i) {
                const std::smatch& match = *i;
                std::string match_str = match.str();

                auto numsBegin = std::sregex_iterator(match_str.begin(), match_str.end(), numberRegex);
                auto numsEnd = std::sregex_iterator();

                std::vector<int> multiplication;
                for (std::sregex_iterator n = numsBegin; n != numsEnd; ++n) {
                    const std::smatch& numberMatch = *n;
                    multiplication.push_back(std::stoi(numberMatch.str()));
                }

                input.multiplications.push_back(multiplication);
            }
        }

        file.close();

        return input;
    }

    Input Solver::readInputV2(std::string path) {
        std::ifstream file(path);

        assert(file.is_open());

        Input input;
        std::regex mulRegex(R"(mul\([0-9]+,[0-9]+\)|do\(\)|don't\(\))");
        std::regex numberRegex("[0-9]+");
        bool isMultDisabled = false;

        for (std::string line; std::getline(file, line);) {
            auto wordsBegin = std::sregex_iterator(line.begin(), line.end(), mulRegex);
            auto wordsEnd = std::sregex_iterator();

            for (std::sregex_iterator i = wordsBegin; i != wordsEnd; ++i) {
                const std::smatch& match = *i;
                std::string match_str = match.str();

                if (match_str == "do()") {
                    isMultDisabled = false;
                }
                if (match_str == "don't()") {
                    isMultDisabled = true;
                }

                if (isMultDisabled) {
                    continue;
                }

                auto numsBegin = std::sregex_iterator(match_str.begin(), match_str.end(), numberRegex);
                auto numsEnd = std::sregex_iterator();

                std::vector<int> multiplication;
                for (std::sregex_iterator n = numsBegin; n != numsEnd; ++n) {
                    const std::smatch& numberMatch = *n;
                    multiplication.push_back(std::stoi(numberMatch.str()));
                }

                input.multiplications.push_back(multiplication);
            }
        }

        file.close();

        return input;
    }


    bool Solver::isPartOneValid() {
        input = readInput("src/days/day3/test.txt");
        const int total = solvePartOne();

        std::ifstream file("src/days/day3/test_answer_1.txt");
        assert(file.is_open());

        std::string line;
        std::getline(file, line);

        return std::stoi(line) == total;
    };

    bool Solver::isPartTwoValid() {
        input = readInputV2("src/days/day3/test.txt");
        const int total = solvePartTwo();

        std::ifstream file("src/days/day3/test_answer_2.txt");
        assert(file.is_open());

        std::string line;
        std::getline(file, line);

        return std::stoi(line) == total;
    };

    int multiply(std::vector<std::vector<int>> multiplications) {
        int total = 0;

        for (auto multiplication : multiplications) {
            int result = 0;

            for (auto number : multiplication) {
                if (result == 0) {
                    result = number;
                }
                else {
                    result *= number;
                }
            }

            total += result;
        }

        return total;
    }

    int Solver::solvePartOne() {
        return multiply(input.multiplications);
    }

    int Solver::solvePartTwo() {
        return multiply(input.multiplications);
    }
}
