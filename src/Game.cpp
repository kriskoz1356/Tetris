#include "Game.h"
#include <stdexcept>
#include <iostream>

void Game::processEvents()
{
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }

        if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
            if (key->scancode == sf::Keyboard::Scancode::Escape) {
                window.close();
            }
            if (key->scancode == sf::Keyboard::Scancode::Left) {
                if (canMove({ -1,0 })) {
                    currentPiece.move({ -1, 0 });
                }
            }
            if (key->scancode == sf::Keyboard::Scancode::Right) {
                if (canMove({ 1, 0 })) {
                    currentPiece.move({ 1, 0 });
                }
            }
            if (key->scancode == sf::Keyboard::Scancode::Down) {
                if (canMove({ 0,1 })) {
                    currentPiece.move({ 0,1 });
                }
            }
            if (key->scancode == sf::Keyboard::Scancode::Up) {
                currentPiece.rotate();
                if(!canMove({ 0,0 })) {
                    currentPiece.rotateBack();
                }
            }
            if (key->scancode == sf::Keyboard::Scancode::Enter) {
                while(canMove({0,1})){
                    currentPiece.move({0, 1});
                }
                lockPiece();
                score += board.clearFullLines();
                spawnPiece();
            }
            if(key->scancode == sf::Keyboard::Scancode::Space){
                restart();
            }
        }
    }
}

void Game::update(float dt) {
    if(gameOver){
        return;
    }

    fallTimer += dt;

    if (fallTimer >= fallDelay) {
        fallTimer = 0.f;
        if (canMove({ 0,1 })) {
            currentPiece.move({ 0,1 });
        }
        else {
            lockPiece();
            score += board.clearFullLines();
            spawnPiece();
            // currentPiece = Tetromino(TetrominoType::O);
        }
    }
}

void Game::render()
{
    window.clear(sf::Color(30, 30, 30));
    sf::RectangleShape gridLine;
    gridLine.setFillColor(sf::Color(60, 60, 60));

    sf::RectangleShape cell({ 30.f,30.f });
    cell.setFillColor(sf::Color::White);


    // Grid
    for (int x = 0; x < Board::Width; ++x) {
        gridLine.setPosition({ x * 32.f,0.f });
        gridLine.setSize({ 2.f,Board::Height * 32.f });
        window.draw(gridLine);
    }

    for (int y = 0; y < Board::Height; ++y) {
        gridLine.setPosition({ 0.f,y * 32.f });
        gridLine.setSize({ Board::Width * 32.f, 2.f });
        window.draw(gridLine);
    }


    // Board 
    for (int y = 0; y < Board::Height; ++y) {
        for (int x = 0; x < Board::Width; ++x) {
            if (board.get(x, y) == Cell::Filled) {
                cell.setPosition({ x * 32.f,y * 32.f });

                window.draw(cell);
            }
        }
    }

    // Ghost Piece
    sf::RectangleShape ghostCell({30.f, 30.f});
    ghostCell.setFillColor(sf::Color(100, 100, 100));

    const auto ghostPosition = getGhostPosition();

    for (const auto& block : currentPiece.getBlocks()){
        ghostCell.setPosition({(ghostPosition.x + block.x) * 32.f,
                               (ghostPosition.y + block.y) * 32.f});
        window.draw(ghostCell);
    }

    // Piece
    const auto &blocks = currentPiece.getBlocks();
    const auto position = currentPiece.getPosition();

    for (const auto& block : blocks) {
        cell.setPosition({
            (position.x + block.x) * 32.f,
            (position.y + block.y) * 32.f
            });
        window.draw(cell);
    }


    // Score
    scoreText.setString("Score: " + std::to_string(score));
    window.draw(scoreText);

    window.display();
}

bool Game::canMove(const sf::Vector2i& offset) const
{
    const auto& blocks = currentPiece.getBlocks();
    const auto position = currentPiece.getPosition();

    for (const auto& block : blocks) {
        int x = position.x + block.x + offset.x;
        int y = position.y + block.y + offset.y;

        if (x < 0 || x >= Board::Width) {
            return false;
        }

        if (y < 0 || y >= Board::Height) {
            return false;
        }

        if (board.get(x, y) == Cell::Filled) {
            return false;
        }
    }
    return true;

}

void Game::lockPiece() {
    const auto& blocks = currentPiece.getBlocks();
    const auto position = currentPiece.getPosition();

    for (const auto& block : blocks) {
        int x = position.x + block.x;
        int y = position.y + block.y;

        board.set(x, y, Cell::Filled);
    }
}

void Game::spawnPiece() {
    currentPiece = TetrominoType(randomize.getRandomType());
    int startX = randomize.getInt(0, Board::Width - 4);
    currentPiece.setPosition({startX, 0});

    if(!canMove({0,0})){
        gameOver = true;
        std::cout << "GEJ OVER" << std::endl;
    }
}

void Game::restart() {
    board.clear();
    score = 0;
    gameOver = false;
    spawnPiece();
}

sf::Vector2i Game::getGhostPosition() const {
    sf::Vector2i ghostPosition = currentPiece.getPosition();

    while(true){
        bool canFall = true;

        for(const auto& block : currentPiece.getBlocks()){
            int x = ghostPosition.x + block.x;
            int y = ghostPosition.y + block.y + 1;

            if(x < 0 || x >= Board::Width || y < 0 || y >= Board::Height || board.get(x,y) == Cell::Filled){
                canFall = false;
                break;
            }
        }
        if(!canFall){
            break;
        }
        ++ghostPosition.y;
    }
    return ghostPosition;
}

Game::Game() : window(sf::VideoMode({ 640,700 }), "Tetris"), currentPiece(randomize.getRandomType()), scoreText(font) {
    window.setFramerateLimit(60);

    // Font 
    if(!font.openFromFile("assets/fonts/PressStart2P-Regular.ttf")){
        throw std::runtime_error("Cannot open font file!");
    }
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition({350.f, 50.f});
};

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        processEvents();
        update(dt);
        render();
    }
}
