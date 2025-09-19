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
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderFillRect(renderer, &box);

    // Load font 
    TTF_Font* arial = openFont("ARIAL.TTF", 20);
    if (!arial) {
        std::cerr << "Font Error: " << TTF_GetError() << std::endl;
        return; // Don’t kill app inside render call
    }

    // Render text surface
    SDL_Color white = {255, 255, 255, 255};
    SDL_Surface* textSurface = TTF_RenderText_Solid(arial, baseText.c_str(), white);
    if (!textSurface) {
        std::cerr << "Text Surface Error: " << TTF_GetError() << std::endl;
        TTF_CloseFont(arial);
        return;
    }

    // Create texture
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (!textTexture) {
        std::cerr << "Texture Error: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(textSurface);
        TTF_CloseFont(arial);
        return;
    }

    // Text destination rect
    SDL_Rect textRect = { box.x + 10, box.y + 10, textSurface->w, textSurface->h };

    // Now free surface
    SDL_FreeSurface(textSurface);

    // Copy texture to renderer
    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);

    // Cleanup
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(arial);
}


void TextBox::handleEverything() {
    if (e.type == SDL_MOUSEBUTTONDOWN && isInside(box)) {
        if (!active) {
            active = true;
            SDL_StartTextInput();
            std::cout << "Textbox activated\n";
        }
    } else if (e.type == SDL_MOUSEBUTTONUP && !isInside(box)) {
        if (active) {
            active = false;
            SDL_StopTextInput();
            std::cout << "Textbox deactivated\n";
        }
    }
}


