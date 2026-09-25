#pragma once
#include <random>
#include "Tetromino.h"

class Randomize {
private:
    std::default_random_engine randomEngine;
    std::uniform_int_distribution<int> randomInt;
public:
    Randomize();
    TetrominoType getRandomType();
    int getInt(int min, int max);
};