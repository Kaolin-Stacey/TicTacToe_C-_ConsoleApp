@echo off
setlocal EnableDelayedExpansion

:: Debugging: Show current directory
echo Current directory: %cd%

:: Initialize an empty variable to hold the list of source files
set SRC_FILES=

:: Loop through all .cpp files in the src directory and append to the variable
for %%f in (src\*.cpp) do (
    echo Adding source file: %%f
    set SRC_FILES=!SRC_FILES! %%f
)

:: Add the FreeType source files from src
for %%f in (external\freetype\src\**\*.c) do (
    echo Adding FreeType source file: %%f
    set SRC_FILES=!SRC_FILES! %%f
)

:: Show the full source list being compiled
echo Full source list: !SRC_FILES! !IMG_SRC!

:: Compile and link the program with the necessary libraries
g++ -g !SRC_FILES! !IMG_SRC! ^
    -Iinclude ^
    -Iexternal\glfw ^
    -Llib ^
    -Lexternal\glfw\lib ^
    -lglfw3 ^
    -lopengl32 ^
    -lgdi32 ^
    -Iexternal\freetype\include ^
    -o build\TicTacToe.exe

:: End local environment
endlocal
