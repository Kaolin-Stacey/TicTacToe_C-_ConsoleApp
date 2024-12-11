//
// Created by kaolin on 2024-12-10.
//

#include "TicTacToe.h"

#include <iostream>
#include <limits>
#include <ostream>
#include <thread>
using namespace std;

constexpr int WIN_WEIGHT = 200;
constexpr int BLOCK_WEIGHT = 90; // the weight of blocking an opponent from a win
constexpr int FORK_WEIGHT = 75; // not implemented
constexpr int FORK_BLOCK_WEIGHT = 200; // not implemented
constexpr int CENTRE_WEIGHT = 75;
constexpr int CORNER_WEIGHT = 40;
constexpr int EDGE_WEIGHT = 10;

TicTacToe::TicTacToe(char player1, char player2) {
    Player1 = player1;
    Player2 = player2;
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
    winner = check_win_condition();
    return winner != ' ' || turn > 9;
}
char TicTacToe::check_win_condition() {
    int diag_r_count = 0;
    int diag_l_count = 0;

    //check rows and right diagonal
    for (int i = 0; i < 3; i++) {
        int col_count = 0; // must reinitialise col count each iteration
        int row_count = 0; // must reinitialise row count each iteration
        for (int j=0; j < 3; j++) {
            // check right diagonal
            if (i==j) {
                if (board[i][j]==Player1) diag_r_count++;
                if (board[i][j]==Player2) diag_r_count--;
            }
            // check left diagonal
            if (i + j == 2) { // since possibilities: (0,2), (1,1), (2,0)
                if (board[i][j] == Player1) diag_l_count++;
                if (board[i][j] == Player2) diag_l_count--;
            }
            //check rows
            if (board[i][j]==Player1) row_count++;
            if (board[i][j]==Player2) row_count--;

            // check columns
            if (board[j][i]==Player1) col_count++;
            if (board[j][i]==Player2) col_count--;
        }
        if (row_count==3 || col_count==3 || diag_r_count==3 || diag_l_count==3) {
            return Player1;
        }
        if (row_count==-3 || col_count==-3 || diag_r_count==-3 || diag_l_count==-3) {
            return Player2;
        }
    }
    return ' ';
}
void TicTacToe::printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|"; // Vertical divider
        }
        cout << endl;
        if (i < 2) cout << "-----------" << endl; // Horizontal divider
    }
}
char TicTacToe::player() {
    if (turn%2+1==1) return Player2;
    return Player1;
}
void TicTacToe::askPlayerForInput() {
    int row, col;

    while (true) {
        cout << "Turn " << turn << ": Player " << player() << endl;
        cout << "Select a row and column between 1 and 3 (ex. 2 1): ";
        cin >> row >> col;
        if (row<1 || row>3 || col<1 || col>3) {
            cout << endl <<  "Invalid input. Try again." << endl;
            continue;
        }
        if (board[row-1][col-1] == Player1 || board[row-1][col-1] == Player2) {
            cout << endl << "Cell already taken. Try again." << endl;
            continue;
        }
        break;
    }
    play(row-1,col-1);
}
void TicTacToe::AI_turn() {
    // AI will always be Player2
    cout << "Turn " << turn << ": AI " << endl;
    cout << endl << "AI is thinking..." << endl;
    this_thread::sleep_for(chrono::seconds(1));
    int row, col;
    find_best_move(row, col);
    play(row, col);
}
void TicTacToe::find_best_move(int &row, int &col) {
    int best_move_weight = -1000;  // Start with a very low value to find the highest weight
    int best_move_row = -1;
    int best_move_col = -1;

    bool found_valid_move = false;  // Flag to track if we find any valid moves

    // Loop through the board to find the best possible move
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {  // Only consider empty spaces
                found_valid_move = true;  // Found at least one valid move
                int weight = determine_weight_of_move(i, j);

                // Update the best move if this one has a higher weight
                if (weight > best_move_weight) {
                    best_move_weight = weight;
                    best_move_row = i;
                    best_move_col = j;
                }
            }
        }
    }

    // If no valid moves were found, output an error
    if (!found_valid_move) {
        cerr << "Error: No valid moves found!" << endl;
    } else {
        row = best_move_row;
        col = best_move_col;
    }
}
int TicTacToe::determine_weight_of_move(int row, int col) { // this is for AI only, so it is automatically for Player2
    int weight = 0;

    // Check if the cell is already taken
    if (board[row][col] != ' ') return 0;

    // Check for possible win
    board[row][col] = Player2;
    if (check_win_condition() == Player2) weight += WIN_WEIGHT;

    // Check for possible blocking
    board[row][col] = Player1;
    if (check_win_condition() == Player1) weight += BLOCK_WEIGHT;

    // Reset the board position after checking
    board[row][col] = ' ';

    // Add positional weights (ensure the centre has the highest priority)
    if (row == 1 && col == 1) weight += CENTRE_WEIGHT;  // Centre should have the highest weight
    if ((row == 0 || row == 2) && (col == 0 || col == 2)) weight += CORNER_WEIGHT;  // Corner
    if (((row == 0 || row == 2) && col == 1) || (row == 1 && (col == 0 || col == 2))) weight += EDGE_WEIGHT;  // Edge

    return weight;
}
void TicTacToe::playerVsAi() {
    while (!gameover()) {
        printBoard();
        if (player() == Player1) {
            askPlayerForInput();  // Player 1's turn
        } else {
            AI_turn();  // AI's turn
        }
        turn++;  // Increment turn after both moves are done
    }
    printBoard();
    if (winner==' ') cout << "It's a tie!" << endl;
    else {
        if (winner==Player1) cout << "Player 1 wins!" << endl;
        else cout << "AI wins!" << endl;
    }
}
void TicTacToe::playerVsPlayerLocal() {
    while (!gameover()) {
        printBoard();
        askPlayerForInput();
        turn++;
    }
    printBoard();
    if (winner==' ') cout << "It's a tie!" << endl;
    else {
        if (winner==Player1) cout << "Player 1 wins!" << endl;
        else cout << "Player 2 wins!" << endl;
    }
}
void TicTacToe::playerVsPlayerOnline() {}
TicTacToe::~TicTacToe() {
}

