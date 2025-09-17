#include "../include/pch.hpp"
#include "../include/shell.hpp"
#include "../include/fontUtils.hpp"
#include "../include/Parser_Lexer.hpp"

int main() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    if (TTF_Init() != 0) {
        SDL_Log("TTF_Init failed: %s", TTF_GetError());
        SDL_Quit();
        TTF_Quit();
        return 1;
    }


    SDL_Window* window = SDL_CreateWindow("Shell",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600, SDL_WINDOW_SHOWN
    );
    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(
        window, -1,
        SDL_RENDERER_ACCELERATED)
    ;
    if (!renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Pass to the shell
    // shell(window, renderer);

    std::string action = "print Hello, World!";
    Parser parser;
    Lexer lexer;
    lexer.setTokens(parser.tokenize(action));
    ActionType actionType = lexer.executeTokens();
    std::string output = lexer.ExecuteCommand(actionType);
    std::cout << output << std::endl;

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TTF_Quit();
    SDL_Quit();

    return 0;
}