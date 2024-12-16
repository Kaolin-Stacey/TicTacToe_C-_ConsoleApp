/*
** EPITECH PROJECT, 2024
** TicTacToe
** File description:
** main
*/

#include "GLFWApp.h"
#include <iostream>


int main() {
    try {
        GLFWApp app(800, 600, "TicTacToe");
        app.run();
    }
    catch (const std::exception& e) {
        std::cerr << "Application error: " << e.what() << std::endl;
        return -1;
    }
    //TicTacToe ttt = TicTacToe('X', 'O');
    //ttt.start();

    return 0;
}
