//
// Created by kaolin on 2024-12-10.
//

#include "TicTacToe.h"

#include <iostream>
#include <limits>
#include <ostream>
using namespace std;

TicTacToe::TicTacToe() {
    turn = 1;
}

void TicTacToe::start() {
    // Check what the player wants to do
    int option {};

    cout << "Select an option:\n1) Player vs AI\n2) Player vs Player (Local)\n3) Player vs Player (Online)" << endl;

    // Ensure that you get a valid option, and to continue asking until player chooses a valid option
    while (true) {
        if (!(cin >> option)) {
            cout << "Invalid input! Please enter a valid integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (option<1||option>3) {
            cout << "Input out of range! Please enter an integer between 1 and 3: ";
        } else break;
    }

    switch (option) {
        case 1:
            playerVsAi();
            break;
        case 2:
            playerVsPlayerLocal();
            break;
        case 3:
            playerVsPlayerOnline();
            break;
    }
}
void TicTacToe::play(int row, int col) {
    board[row][col] = player();
}
bool TicTacToe::gameover() {

    int diag_r_count = 0;
    int diag_l_count = 0;

    //check rows and right diagonal
    for (int i = 0; i < 3; i++) {
        int col_count = 0; // must reinitialise col count each iteration
        int row_count = 0; // must reinitialise row count each iteration
        for (int j=0; j < 3; j++) {
            // check right diagonal
            if (i==j) {
                if (board[i][j]=='X') diag_r_count++;
                if (board[i][j]=='O') diag_r_count--;
            }
            // check left diagonal
            if (i + j == 2) { // since possibilities: (0,2), (1,1), (2,0)
                if (board[i][j] == 'X') diag_l_count++;
                if (board[i][j] == 'O') diag_l_count--;
            }
            //check rows
            if (board[i][j]=='X') row_count++;
            if (board[i][j]=='O') row_count--;

            // check columns
            if (board[j][i]=='X') col_count++;
            if (board[j][i]=='O') col_count--;
        }
        if (row_count==3 || col_count==3 || diag_r_count==3 || diag_l_count==3) {
            winner = 'X';
            return true;
        }
        if (row_count==-3 || col_count==-3 || diag_r_count==-3 || diag_l_count==-3) {
            winner = 'O';
            return true;
        }
    }

    if (turn>9) return true;
    return false;
}
void TicTacToe::printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Print the cell with proper spacing
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|"; // Add vertical divider between cells
        }
        cout << endl;
        if (i < 2) cout << "---+---+---" << endl; // Add horizontal divider between rows
    }
}
char TicTacToe::player() {
    if (turn%2+1==1) return 'X';
    return 'O';
}

void TicTacToe::playerVsAi() {}
void TicTacToe::playerVsPlayerLocal() {
    while (!gameover()) {
        cout << "Turn " << turn << ": Player " << player() << endl;
        cout << "Select a row and column between 1 and 3 (ex. 2 1): ";
        int row, col;
        cin >> row >> col;
        if (row<1 || row>3 || col<1 || col>3) {
            cout << endl <<  "Invalid input. Try again." << endl;
            continue;
        }
        if (board[row-1][col-1] == 'X' || board[row-1][col-1] == 'O') {
            cout << endl << "Cell already taken. Try again." << endl;
            continue;
        }
        play(row-1,col-1);
        printBoard();
        turn++;
    }
    if (winner==' ') cout << "It's a tie!" << endl;
    else cout << "Winner: " << winner << endl;
}
void TicTacToe::playerVsPlayerOnline() {}


TicTacToe::~TicTacToe() {
}

