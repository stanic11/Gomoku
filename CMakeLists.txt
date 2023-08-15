cmake_minimum_required(VERSION 3.26)
project(Gomoku)

set(CMAKE_CXX_STANDARD 14)

# Import EasyX library files.
set(EASYX_DIR "YOUR EASYX DIRECTORIES")
include_directories(EASYX_DIR\\include)
link_directories(EASYX_DIR\\lib64)
link_libraries(libeasyx.a)

add_executable(Gomoku include/defines.h
        include/Display.h
        include/main.h
        include/Cursor.h
        include/KeyBoard.h
        src/AI.cpp
        src/chessman.cpp
        src/Cursor.cpp
        src/Display.cpp
        src/KeyBoard.cpp
        src/main.cpp
        src/Display.cpp
)
