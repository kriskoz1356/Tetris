#include "Game.h"

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
        }
    }
}

void Game::update(float dt) {
    fallTimer += dt;

    if (fallTimer >= fallDelay) {
        fallTimer = 0.f;
        if (canMove({ 0,1 })) {
            currentPiece.move({ 0,1 });
        }
        else {
            lockPiece();
            currentPiece = Tetromino{ TetrominoType::I };
        }
    }
}

void Game::render()
{
    window.clear(sf::Color(30, 30, 30));
    sf::RectangleShape cell({ 30.f,30.f });

    cell.setFillColor(sf::Color::White);

    // Plansza 
    for (int y = 0; y < Board::Height; ++y) {
        for (int x = 0; x < Board::Width; ++x) {
            if (board.get(x, y) == Cell::Filled) {
                cell.setPosition({ x * 32.f,y * 32.f });

                window.draw(cell);
            }
        }
    }

    const auto& blocks = currentPiece.getBlocks();
    const auto position = currentPiece.getPosition();

    for (const auto& block : blocks) {
        cell.setPosition({
            (position.x + block.x) * 32.f,
            (position.y + block.y) * 32.f
            });
        window.draw(cell);
    }
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

// TetrominoType Game::randomTetrominoType() {
//     return TetrominoType();
// }

Game::Game() : window(sf::VideoMode({ 640,700 }), "Tetris"), currentPiece(TetrominoType::O) {
    window.setFramerateLimit(60);
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
