#include "Board.h"

Board::Board() {
    clear();
}

void Board::clear() {
    for (auto& row : cells) {
        row.fill(Cell::Empty);
    }
}

Cell Board::get(int x, int y) const {
    return cells[y][x];
}

void Board::set(int x, int y, Cell value) {
    cells[y][x] = value;
}

int Board::clearFullLines() {

    int clearedLines = 0;

    for (int y = 0; y < Height;) {
        bool full = true;

        for (int x = 0; x < Width; ++x) {
            if (cells[y][x] == Cell::Empty) {
                full = false;
                break;
            }
        }

        if (full) {
            for (int row = y; row > 0; --row) {
                cells[row] = cells[row - 1];
            }
            cells[0].fill(Cell::Empty);
            clearedLines++;
        }
        else {
            ++y;
        }
    }
    return clearedLines;
}
