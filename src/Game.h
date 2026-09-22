#pragma once
#include "Board.h"
#include "Tetromino.h"
#include <SFML/Graphics.hpp>

class Game {
private:
    sf::RenderWindow window;
    Board board;
    Tetromino currentPiece;

    float fallTimer = 0.f;
    float fallDelay = 0.5f;

    void processEvents();
    void update(float dt);
    void render();

    bool canMove(const sf::Vector2i& offset) const;
    void lockPiece();

    // TetrominoType randomTetrominoType();
public:
    Game();
    void run();
};