# TicTacToe Game

A simple implementation of TicTacToe with options for Player vs AI, Player vs Player (local), and Player vs Player (online). The game is designed to be played on the terminal with basic input validation.

## Features

- **Player vs AI**: Play against the AI (currently not implemented).
- **Player vs Player (Local)**: Play against another player on the same computer.
- **Player vs Player (Online)**: Play against another player over the network (currently not implemented).
- **Game Logic**: Includes row, column, and diagonal win checks.

## Requirements

- C++20 or higher
- Standard C++ library

## Installation
1) Clone the repo
2) CD into the debug directory
3) Run the exe file
   ```bash
   git clone https://github.com/Kaolin-Stacey/TicTacToe_CPP.git
   cd TicTacToe/cmake-build-debug
   TicTacToe.exe

## How to Play
### Start the Game: Select the mode when prompted:

- **1** for Player vs AI (Not implemented yet).
- **2** for Player vs Player (Local).
- **3** for Player vs Player (Online) (Not implemented yet).

### Gameplay

For Player vs Player (Local), players take turns to input their moves.
Input row and column numbers between 1 and 3 to place their mark (X or O).
The game ends when a player wins or when it’s a tie.

## Code Structure
**TicTacToe.cpp**: Main logic for the game including input validation, board printing, and determining the winner.
**TicTacToe.h**: Header file declaring the TicTacToe class with all functions and member variables.

## Future Improvements
### Fix board: The board in the terminal does not look right
### Windowed App: Change the console app to a windowed app
### AI Implementation: Add functionality for AI gameplay.
### Online Multiplayer: Implement network functionality for online play.

# License
This project is licensed under the MIT License - see the LICENSE file for details.

Acknowledgements
C++ standard libraries.
Game logic ideas inspired by classic TicTacToe implementations.