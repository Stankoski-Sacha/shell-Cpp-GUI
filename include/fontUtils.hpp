//
// Created by balls on 15/09/2025.
//

#ifndef SHELL_FONTUTILS_HPP
#define SHELL_FONTUTILS_HPP

#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>

inline TTF_Font* openFont(const std::string& name, int size) {
    TTF_Font* font = TTF_OpenFont(name.c_str(), size);
    if (!font) {
        std::cerr << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
        return nullptr;
    }

    return font;
}

#endif //SHELL_FONTUTILS_HPP