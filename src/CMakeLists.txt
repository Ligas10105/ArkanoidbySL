cmake_minimum_required(VERSION 3.21)
project(ArkanoidbySL LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(ArkanoidbySL main.cpp ball.cpp ball.cpp Palette.h Palette.h Palette.cpp Block.cpp Block.cpp)
target_link_libraries(ArkanoidbySL PRIVATE sfml-graphics)
target_compile_features(ArkanoidbySL PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET ArkanoidbySL POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:ArkanoidbySL> $<TARGET_FILE_DIR:ArkanoidbySL> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS ArkanoidbySL)
