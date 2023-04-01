set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(gameObjects
    Ball.h
    Ball.cpp 
    Palette.h 
    Palette.cpp)

add_executable(ArkanoidbySL main.cpp ${gameObjects})