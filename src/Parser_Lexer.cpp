//
// Created by balls on 16/09/2025.
//

#include "../include/pch.hpp"
#include "../include/Parser_Lexer.hpp"
#include "../include/commands.hpp"
#include <sstream>

std::vector<std::string> Parser::tokenize(const std::string &input) {
    std::vector<std::string> tokens;

    std::istringstream iss(input);
    std::string word;

    while (iss >> word) {
        tokens.push_back(word);
    }

    // Remove the "~>" from the inputs
    // tokens.erase(tokens.begin());

    return tokens;
}

void Lexer::setTokens(const std::vector<std::string> &token) {
    tokens = token;
}

ActionType Lexer::executeTokens() {
    if (tokens.empty()) {
        return ActionType::NONE;
    }

    // get the command and remove it from the functions
    std::string action = tokens.front();
    tokens.erase(tokens.begin());

    // Action
    if (action == "print") return ActionType::PRINT;
    else if (action == "if") return ActionType::IF;
    else {
        return ActionType::NONE;
    }
}

std::string Lexer::ExecuteCommand(const ActionType& action) const {
    std::string text;
    switch (action) {
        case ActionType::PRINT:
            text = printText(tokens);
            break;
        case ActionType::IF:
            return ifStatement(tokens);
        case ActionType::NONE:
            return " ";
        default:
            return "";
    }

    return text;
}


