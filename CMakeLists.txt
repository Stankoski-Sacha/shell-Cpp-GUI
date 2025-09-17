cmake_minimum_required(VERSION 4.0)
project(shell)

set(CMAKE_CXX_STANDARD 26)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED) # Ajout de SDL2_ttf

add_executable(shell src/main.cpp
        include/pch.hpp
        src/shell.cpp
        include/shell.hpp
        include/fontUtils.hpp
        include/Parser_Lexer.hpp
        src/Parser_Lexer.cpp
        include/commands.hpp
        src/commands.cpp
        src/textbox.cpp
        include/textbox.hpp)

target_link_libraries(shell PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2_ttf::SDL2_ttf)

add_custom_command(TARGET shell POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/src/ARIAL.TTF"
        "$<TARGET_FILE_DIR:shell>/ARIAL.TTF")
