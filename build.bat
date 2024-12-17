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

:: Set the ImGui source files
set IMG_SRC=
for %%f in (external\imgui\*.cpp) do (
    echo Adding ImGui source file: %%f
    set IMG_SRC=!IMG_SRC! %%f
)

for %%f in (external\imgui\backends\*.cpp) do (
    echo Adding ImGui backend source file: %%f
    set IMG_SRC=!IMG_SRC! %%f
)

:: Show the full source list being compiled
echo Full source list: !SRC_FILES! !IMG_SRC!

:: Compile and link the program with the necessary libraries
g++ -g !SRC_FILES! !IMG_SRC! ^
    -Iinclude ^
    -Iexternal\imgui ^
    -Iexternal\imgui\backends ^
    -Iexternal\glfw ^
    -Llib ^
    -Lexternal\glfw\lib ^
    -lglfw3 ^
    -lopengl32 ^
    -lgdi32 ^
    -o build\TicTacToe.exe

:: End local environment
endlocal
