#include "Randomize.h"

Randomize::Randomize()
    : randomEngine(std::random_device{}()), randomInt(0, 6)
{
}

TetrominoType Randomize::getRandomType() {
    return static_cast<TetrominoType>(randomInt(randomEngine));
}

int Randomize::getInt(int min, int max) {
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(randomEngine);
}
