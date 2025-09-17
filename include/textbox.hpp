//
// Created by balls on 17/09/2025.
//

#ifndef SHELL_TEXTBOX_HPP
#define SHELL_TEXTBOX_HPP

#include "pch.hpp"

class TextBox {
private:
    // SDL Elements
    SDL_Rect box;
    SDL_Window* window;
    SDL_Renderer* renderer;

    // Other
    std::string baseText;
    std::string text;
    bool active = false;

public:
    TextBox(SDL_Window* w, SDL_Renderer* r, SDL_Rect b, std::string text);
    ~TextBox();

    void placeOnScreen();
    void handleEverything();
};

#endif //SHELL_TEXTBOX_HPP