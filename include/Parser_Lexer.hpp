//
// Created by balls on 16/09/2025.
//

#ifndef SHELL_PARSER_LEXER_HPP
#define SHELL_PARSER_LEXER_HPP

#include "pch.hpp"

enum class ActionType {
    NONE = 0,
    EXIT = 1,
    CLEAR = 2,
    HELP = 3,
    PRINT = 4,
    IF = 5,
};

class Parser {
public:
    std::vector<std::string> tokenize(const std::string &input);
};

class Lexer {
private:
    std::vector<std::string> tokens;

public:
    void setTokens(const std::vector<std::string> &token);
    ActionType executeTokens();
    std::string ExecuteCommand(const ActionType &action) const;
};

#endif //SHELL_PARSER_LEXER_HPP