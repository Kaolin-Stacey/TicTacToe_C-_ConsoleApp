@echo off
setlocal EnableDelayedExpansion

:: Initialize an empty variable to hold the list of source files
set SRC_FILES=

:: Loop through all .cpp files in the src directory and append to the variable
for %%f in (src\*.cpp) do (
    set SRC_FILES=!SRC_FILES! %%f
)

:: Run g++ with all source files and necessary flags, including GDI and OpenGL libraries
g++ -g !SRC_FILES! -Iinclude -Llib -lglfw3 -lopengl32 -lgdi32 -o build\TicTacToe.exe
