//
// Created by balls on 15/09/2025.
//
#include "../include/pch.hpp"
#include "../include/shell.hpp"
#include <memory>
#include "../include/fontUtils.hpp"
#include "../include/Parser_Lexer.hpp"
#include "../include/textbox.hpp"
#include <SDL2/SDL_ttf.h>

int WINH = 600;
int WINW = 800;

void shell(SDL_Window *window, SDL_Renderer *renderer) {
    // Create parser and lexer
    Parser parser;
    Lexer lexer;

    // Events
    SDL_Event e;
    bool running = true;

    TextBox mainBox(window, renderer, {0, 0, WINW, WINH}, "Hello, World!", e);
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }

            // Clear screen
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            // Place text box
            mainBox.placeOnScreen();
            mainBox.handleEverything();


            SDL_RenderPresent(renderer);
            SDL_Delay(16);
        }
    }
}