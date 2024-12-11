//
// Created by kaolin on 2024-12-10.
//

#ifndef TICTACTOE_H
#define TICTACTOE_H



class TicTacToe {
public:
    TicTacToe(char player1='X', char player2='O');
    void start();
    ~TicTacToe();

private:
    char Player1;
    char Player2;

    void playerVsAi();
    void playerVsPlayerLocal();
    void playerVsPlayerOnline();
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    void play(int row, int col);
    int turn {};
    void askPlayerForInput();
    void AI_turn();
    void find_best_move(int &row, int &col);

    int determine_weight_of_move(int row, int col);

    char winner{' '};
    void printBoard();

    char player();

    bool gameover();

    char check_win_condition();
};

#endif //TICTACTOE_H
