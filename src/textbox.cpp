//
// Created by balls on 17/09/2025.
//

#include "../include/pch.hpp"
#include "../include/textbox.hpp"
#include "../include/fontUtils.hpp"

bool isInside(SDL_Rect box) {
    int x, y;
    SDL_GetMouseState(&x, &y);

    return (x >= box.x &&
            x <= box.x + box.w &&
            y >= box.y &&
            y <= box.y + box.h
            );
}

TextBox::TextBox(SDL_Window *w, SDL_Renderer *r, SDL_Rect b, std::string text, SDL_Event e) :
    box(b), window(w), renderer(r), baseText(std::move(text)), e(e) {
}

TextBox::~TextBox() = default;

void TextBox::placeOnScreen() {
    // Box BG
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_RenderFillRect(renderer, &box);

    // Font
    TTF_Font* arial = openFont("ARIAL.TTF", 20);
    if (!arial) {
        std::cerr << "Font Error" << TTF_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
        TTF_Quit();
        exit(1);
    }

    // Surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(arial, text.c_str(), {255, 255, 255});
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);

    // Text
    SDL_Rect textRect = {box.x + 10, box.y + 10, textSurface->w, textSurface->h};
    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);

    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(arial);
}

void TextBox::handleEverything(){
    if (e.type == SDL_MOUSEBUTTONDOWN && isInside(box)) {
        active = true;
    } else if (e.type == SDL_MOUSEBUTTONUP && isInside(box)) {
        active = false;
    }

    if (active) {
        SDL_StartTextInput();
    } else if (!active) {
        SDL_StopTextInput();
    }
}

