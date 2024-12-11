# 0 "C:/Users/kaoli/CLionProjects/TicTacToe/main.cpp"
# 1 "C:\\Users\\kaoli\\CLionProjects\\TicTacToe\\cmake-build-debug//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "C:/Users/kaoli/CLionProjects/TicTacToe/main.cpp"
# 1 "C:/Users/kaoli/CLionProjects/TicTacToe/Game/TicTacToe.h" 1
# 10 "C:/Users/kaoli/CLionProjects/TicTacToe/Game/TicTacToe.h"
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
# 2 "C:/Users/kaoli/CLionProjects/TicTacToe/main.cpp" 2

int main() {
    TicTacToe ttt = TicTacToe('X','O');
    ttt.start();
    return 0;
}
