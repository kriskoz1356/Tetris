# Tetris by kriskoz
A simple Tetris implementation done using SFML in C++

## Features

### Currently implemented:
* 10x20 board,
* 7 types of Tetromino
* Pieces spawn randomly
* Pieces fall
* Pieces can be rotated
* When full line is cleared, player scores a point
* Ghost piece to know where the landing point is
* Restart button (Space)

### Planned additions:
* Score will depend on the number of cleared lines at once
* Music will be added
* UI will look way more user-friendly
* Next piece will be visible
* Combo system

## Controls

| Key      | Action                  |
| -------- | ----------------------- |
| `←`      | Move left               |
| `→`      | Move right              |
| `↓`      | Move down               |
| `Enter`  | Hard drop               |
| `Escape` | Exit game               |
| `Space`  | Restart after Game Over |

## Requirements
* C++ compiler
* CMake Tools
* SFML 3

Visual Studio Code is recommended.

## Building

Clone the repository:

```bash
git clone https://github.com/kriskoz1356/Tetris.git
cd Tetris
```

Create a build directory:

```bash
cmake -S . -B build
```

Build the project:

```bash
cmake --build build
```

Run the game:

```bash
./build/Tetris
```
Remember to run the game while being in the **`/Tetris`** folder.

## Project Structure

```text
Tetris/
├── assets/
│   └── fonts/
│       └── PressStart2P-Regular.ttf
│
├── src/
│   ├── Board/
│   │   ├── Board.h
│   │   └── Board.cpp
│   │
│   ├── Randomize/
│   │   ├── Randomize.h
│   │   └── Randomize.cpp
│   │
│   ├── Tetromino/
│   │   ├── Tetromino.h
│   │   └── Tetromino.cpp
│   │
│   ├── Game.h
│   ├── Game.cpp
│   └── main.cpp
│
├── CMakeLists.txt
└── README.md
```