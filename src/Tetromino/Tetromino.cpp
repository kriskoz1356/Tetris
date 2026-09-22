#include "Tetromino.h"

Tetromino::Tetromino(TetrominoType type) : position{ 4,0 }, type{ type } {
    switch (type) {
    case TetrominoType::I:
        blocks = {
            sf::Vector2i{ 0,1 },
            sf::Vector2i{ 1,1 },
            sf::Vector2i{ 2,1 },
            sf::Vector2i{ 3,1 }
        };
        break;
    case TetrominoType::O:
        blocks = {
            sf::Vector2i{ 1,0 },
            sf::Vector2i{ 2,0 },
            sf::Vector2i{ 1,1 },
            sf::Vector2i{ 2,1 }
        };
        break;
    case TetrominoType::T:
        blocks = {
            sf::Vector2i{ 1,0 },
            sf::Vector2i{ 0,1 },
            sf::Vector2i{ 1,1 },
            sf::Vector2i{ 2,1 }
        };
        break;
    case TetrominoType::S:
        blocks = {
            sf::Vector2i{ 1,0 },
            sf::Vector2i{ 2,0 },
            sf::Vector2i{ 0,1 },
            sf::Vector2i{ 1,1 }
        };
        break;
    case TetrominoType::Z:
        blocks = {
            sf::Vector2i{ 0,0 },
            sf::Vector2i{ 1,0 },
            sf::Vector2i{ 1,1 },
            sf::Vector2i{ 2,1 }
        };
        break;
    case TetrominoType::J:
        blocks = {
            sf::Vector2i{ 0,0 },
            sf::Vector2i{ 0,1 },
            sf::Vector2i{ 1,1 },
            sf::Vector2i{ 2,1 }
        };
        break;
    case TetrominoType::L:
        blocks = {
            sf::Vector2i{ 2,0 },
            sf::Vector2i{ 0,1 },
            sf::Vector2i{ 1,1 },
            sf::Vector2i{ 2,1 }
        };
        break;
    }
}

const std::array<sf::Vector2i, 4>& Tetromino::getBlocks() const
{
    return blocks;
}

sf::Vector2i Tetromino::getPosition() const
{
    return position;
}

void Tetromino::move(sf::Vector2i offset) {
    position += offset;
}
