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
        rotationCenter = { 1.5f, 1.5f };
        break;
    case TetrominoType::O:
        blocks = {
            sf::Vector2i{ 1,0 },
            sf::Vector2i{ 2,0 },
            sf::Vector2i{ 1,1 },
            sf::Vector2i{ 2,1 }
        };
        rotationCenter = { 1.5f, 0.5f };
        break;
    case TetrominoType::T:
        blocks = {
            sf::Vector2i{ 1,0 },
            sf::Vector2i{ 0,1 },
            sf::Vector2i{ 1,1 },
            sf::Vector2i{ 2,1 }
        };
        rotationCenter = { 1.0f, 1.0f };
        break;
    case TetrominoType::S:
        blocks = {
            sf::Vector2i{ 1,0 },
            sf::Vector2i{ 2,0 },
            sf::Vector2i{ 0,1 },
            sf::Vector2i{ 1,1 }
        };
        rotationCenter = { 1.0f, 1.0f };
        break;
    case TetrominoType::Z:
        blocks = {
            sf::Vector2i{ 0,0 },
            sf::Vector2i{ 1,0 },
            sf::Vector2i{ 1,1 },
            sf::Vector2i{ 2,1 }
        };
        rotationCenter = { 1.0f, 1.0f };
        break;
    case TetrominoType::J:
        blocks = {
            sf::Vector2i{ 0,0 },
            sf::Vector2i{ 0,1 },
            sf::Vector2i{ 1,1 },
            sf::Vector2i{ 2,1 }
        };
        rotationCenter = { 1.0f, 1.0f };
        break;
    case TetrominoType::L:
        blocks = {
            sf::Vector2i{ 2,0 },
            sf::Vector2i{ 0,1 },
            sf::Vector2i{ 1,1 },
            sf::Vector2i{ 2,1 }
        };
        rotationCenter = { 1.0f, 1.0f };
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

void Tetromino::rotate() {
    if (type == TetrominoType::O) {
        return;
    }
    else{
        for (auto& block : blocks) {
            float x = block.x - rotationCenter.x;
            float y = block.y - rotationCenter.y;

            float rotatedX = -y;
            float rotatedY = x;

            block.x = static_cast<int>(rotatedX + rotationCenter.x);
            block.y = static_cast<int>(rotatedY + rotationCenter.y);
        }
    }
}

void Tetromino::rotateBack() {
    if (type == TetrominoType::O) {
        return;
    }
    else {
        for (auto& block : blocks) {
            float x = block.x - rotationCenter.x;
            float y = block.y - rotationCenter.y;

            float rotatedX = y;
            float rotatedY = -x;

            block.x = static_cast<int>(rotatedX + rotationCenter.x);
            block.y = static_cast<int>(rotatedY + rotationCenter.y);
        }
    }
}

void Tetromino::setPosition(sf::Vector2i position) {
    this->position = position;
}
