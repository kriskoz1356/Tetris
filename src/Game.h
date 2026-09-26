#pragma once
#include "Board.h"
#include "Tetromino.h"
#include "Randomize.h"
#include <SFML/Graphics.hpp>

class Game {
private:
    sf::RenderWindow window;
    Board board;
    Randomize randomize;
    Tetromino currentPiece;
    sf::Font font;
    sf::Text scoreText;

    bool gameOver = false;
    float fallTimer = 0.f;
    float fallDelay = 0.5f;
    int score = 0;

    void processEvents();
    void update(float dt);
    void render();

    bool canMove(const sf::Vector2i& offset) const;
    void lockPiece();
    void spawnPiece();

    void restart();

    sf::Vector2i getGhostPosition() const;

public:
    Game();
    void run();
};