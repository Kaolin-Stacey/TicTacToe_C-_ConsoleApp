cmake_minimum_required(VERSION 3.30)


set(CMAKE_TOOLCHAIN_FILE "C:/Libraries/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

project(TicTacToe)

set(CMAKE_CXX_STANDARD 20)


set(Boost_USE_STATIC_LIBS ON)  # Use static Boost libraries
set(Boost_USE_DEBUG_LIBS OFF)  # Ignore debug libraries
set(Boost_USE_RELEASE_LIBS ON)  # Use release libraries
set(Boost_USE_MULTITHREADED ON)  # Enable multithreading
set(Boost_USE_STATIC_RUNTIME ON)  # Link Boost statically

find_package(Boost REQUIRED COMPONENTS asio)

add_executable(TicTacToe main.cpp
        Game/TicTacToe.cpp
        Game/TicTacToe.h
        Network/Network.cpp
        Network/Network.h)

target_link_libraries(TicTacToe PRIVATE Boost::asio ws2_32)
