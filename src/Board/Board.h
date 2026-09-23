#pragma once
#include <array>

enum class Cell {
    Empty,
    Filled
};

class Board {
public:
    static constexpr int Width = 10;
    static constexpr int Height = 20;
private:
    std::array<std::array<Cell, Width>, Height>cells;
public:
    Board();
    void clear();
    Cell get(int x, int y) const;
    void set(int x, int y, Cell value);

    int clearFullLines();
};