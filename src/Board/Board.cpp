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