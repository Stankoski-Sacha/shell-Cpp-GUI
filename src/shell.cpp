//
// Created by balls on 15/09/2025.
//
#include "../include/pch.hpp"
#include "../include/shell.hpp"

#include <memory>

#include "../include/fontUtils.hpp"
#include "../include/Parser_Lexer.hpp"
#include <SDL2/SDL_ttf.h>

int WINH = 600;
int WINW = 800;

bool isInside(SDL_Rect box) {
    int x, y;
    SDL_GetMouseState(&x, &y);

    return (x >= box.x &&
            x <= box.x + box.w &&
            y >= box.y &&
            y <= box.y + box.h
            );
}

void shell(SDL_Window *window, SDL_Renderer *renderer) {
    // Create parser and lexer
    Parser parser;
    Lexer lexer;

    // Events
    SDL_Event e;
    bool running = true;


    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }

            // Clear screen
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            SDL_RenderPresent(renderer);
            SDL_Delay(16);
        }
    }
}