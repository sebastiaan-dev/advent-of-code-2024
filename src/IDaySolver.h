//
// Created by Sebastiaan Gerritsen on 25/02/2025.
//

#ifndef IDAYSOLVER_H
#define IDAYSOLVER_H
#include <array>
#include <iostream>

struct Solution {
    int partOne;
    int partTwo;
};

class IDaySolver {
public:
    virtual ~IDaySolver() = default;

    virtual Solution solve() = 0;

    void isValid() {
        bool partOne = isPartOneValid();
        bool partTwo = isPartTwoValid();

        if(partOne) {
            std::cout << "Part One: " << "\033[1;32mPASS\033[0m\n";
        } else {
            std::cout << "Part One: " << "\033[1;31mFAIL\033[0m\n";
        };

        if(partTwo) {
            std::cout << "Part Two: " << "\033[1;32mPASS\033[0m\n";
        } else {
            std::cout << "Part Two: " << "\033[1;31mFAIL\033[0m\n";
        }
    }

private:
    virtual bool isPartOneValid() = 0;
    virtual bool isPartTwoValid() = 0;
};



#endif //IDAYSOLVER_H
