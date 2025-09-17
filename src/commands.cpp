//
// Created by balls on 16/09/2025.
//

#include "../include/pch.hpp"
#include "../include/commands.hpp"
#include "../include/Parser_Lexer.hpp"
#include <algorithm>
#include <cstdlib>

bool isInt(const std::string& num) {
    for (char c : num) {
        if (!isdigit(c)) {
            return false;
        }
    }

    return true;
}

std::string printText(const std::vector<std::string>& tokens) {
    std::string text;

    for (const std::string& words : tokens) {
        text += words + " ";
    }

    return text;
}

std::string ifStatement(std::vector<std::string> tokens) {
    if (tokens.empty()) {
        return "Invalid use of the IF";
    }

    auto thenIt = std::find(tokens.begin(), tokens.end(), "then");
    if (thenIt == tokens.end()) {
        return "Missing 'then' keyword";
    }

    bool hasElse = false;
    auto elseIt = std::find(thenIt+1, tokens.end(), "else");
    if (elseIt != tokens.end()) {
        hasElse = true;
    }

    // Actual if
    bool compInt = false;
    Parser parser;
    Lexer lexer;
    std::string toReturn;

}