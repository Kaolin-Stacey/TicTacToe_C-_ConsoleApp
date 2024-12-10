//
// Created by kaolin on 2024-12-10.
//

#ifndef TICTACTOE_H
#define TICTACTOE_H



class TicTacToe {
public:
    TicTacToe();
    void start();
    ~TicTacToe();
private:
    void playerVsAi();
    void playerVsPlayerLocal();
    void playerVsPlayerOnline();
    char board[3][3] = {{" "}};
    void play(int row, int col);
    int turn {};

    char player();
    char winner{' '};
    void printBoard();
    bool gameover();
};

#endif //TICTACTOE_H
