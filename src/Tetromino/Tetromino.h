#pragma once
#include <array>
#include <SFML/System/Vector2.hpp>

enum class TetrominoType {
    I,
    O,
    T,
    S,
    Z,
    J,
    L
};

class Tetromino {
private:
    std::array<sf::Vector2i, 4>blocks;
    sf::Vector2i position;
    sf::Vector2f rotationCenter;
    TetrominoType type;
public:
    Tetromino(TetrominoType type);
    const std::array<sf::Vector2i, 4>& getBlocks() const;
    sf::Vector2i getPosition() const;
    void move(sf::Vector2i offset);
    void rotate();
    void rotateBack();
};