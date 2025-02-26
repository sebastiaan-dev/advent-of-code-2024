//
// Created by Sebastiaan Gerritsen on 25/02/2025.
//

#include "solver.h"

#include <fstream>
#include <assert.h>
#include <iostream>
#include <list>
#include <map>

namespace day1 {
    Input Solver::readInput(std::string path) {
        std::ifstream file(path);

        assert(file.is_open());

        Input input;

        for (std::string line; std::getline(file, line);) {
            size_t startWhitespace = line.find_first_of(' ');
            size_t endWhitespace = line.find_last_of(' ');

            std::string leftNumber = line.substr(0, startWhitespace);
            std::string rightNumber = line.substr(endWhitespace + 1);

            input.leftList.insert(input.leftList.end(), std::stoi(leftNumber));
            input.rightList.insert(input.rightList.end(), std::stoi(rightNumber));
        }

        file.close();

        return input;
    }


    bool Solver::isPartOneValid() {
        input = readInput("src/days/day1/test.txt");
        const int distance = solvePartOne();

        std::ifstream file("src/days/day1/test_answer_1.txt");
        assert(file.is_open());

        std::string line;
        std::getline(file, line);

        return std::stoi(line) == distance;
    };

    bool Solver::isPartTwoValid() {
        input = readInput("src/days/day1/test.txt");
        const int similarity = solvePartTwo();

        std::ifstream file("src/days/day1/test_answer_2.txt");
        assert(file.is_open());

        std::string line;
        std::getline(file, line);

        return std::stoi(line) == similarity;
    };

    int Solver::solvePartOne() {
        std::vector<int> left = input.leftList;
        std::vector<int> right = input.rightList;

        std::ranges::sort(left);
        std::ranges::sort(right);

        assert(left.size() == right.size());

        int distance = 0;
        for (size_t i = 0; i < left.size(); ++i) {
            distance += std::abs(left[i] - right[i]);
        }

        return distance;
    }

    int Solver::solvePartTwo() {
        std::vector<int> left = input.leftList;
        std::vector<int> right = input.rightList;

        std::map<int, int> numberCount;

        for (int element : right) {
            numberCount[element]++;
        }

        int sum = 0;

        for (int i : left) {
            sum += i * numberCount[i];
        }

        return sum;
    }
}