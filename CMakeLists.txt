cmake_minimum_required(VERSION 3.21)
project(ArkanoidbySL LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

include_directories(src)
add_subdirectory(src)

target_link_libraries(ArkanoidbySL PRIVATE sfml-graphics)

target_compile_features(ArkanoidbySL PRIVATE cxx_std_17)

install(TARGETS ArkanoidbySL)
