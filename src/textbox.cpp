//
// Created by balls on 17/09/2025.
//

#include "../include/pch.hpp"
#include "../include/textbox.hpp"
#include "../include/fontUtils.hpp"


TextBox::TextBox(SDL_Window *w, SDL_Renderer *r, SDL_Rect b, std::string text) :
    box(b), window(w), renderer(r), baseText(std::move(text)) {
}

TextBox::~TextBox() = default;

void TextBox::placeOnScreen() {
    // Box BG
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_RenderFillRect(renderer, &box);

    // Font
    TTF_Font* arial = openFont("ARIAL.TTF", 20);

    // Surface

}

void TextBox::handleEverything() {

}

