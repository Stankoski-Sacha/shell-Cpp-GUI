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

    std::vector<std::string> thenTokens;
    std::vector<std::string> elseTokens;

    if (hasElse) {
        thenTokens = std::vector<std::string>(thenIt + 1, elseIt);
        elseTokens = std::vector<std::string>(elseIt + 1, tokens.end());
    } else {
        thenTokens = std::vector<std::string>(thenIt + 1, tokens.end());
    }




    // Actual if
    bool compInt = false;
    Parser parser;
    Lexer lexer;
    std::string toReturn;

    std::string arg1 = tokens[0];
    const char* op = tokens[1].c_str();
    std::string arg2 = tokens[2];
    int intArg1, intArg2;

    if (isInt(arg1) && isInt(arg2)) {
        intArg1 = std::stoi(arg1);
        intArg2 = std::stoi(arg2);
        compInt = true;
    }

    // Check if condition is true
    bool condition = false;

    if (strcmp(op, "==") == 0) {
        if (!compInt) {
            condition = (strcmp(arg1.c_str(), arg2.c_str()) == 0);
        } else {
            condition = (intArg1 == intArg2);
        }
    } else if (strcmp(op, "!=") == 0) {
        if (!compInt) {
            condition = (strcmp(arg1.c_str(), arg2.c_str()) != 0);
        } else {
            condition = (intArg1 != intArg2);
        }
    } else if (strcmp(op, ">") == 0) {
        if (!compInt) {
            condition = (strcmp(arg1.c_str(), arg2.c_str()) > 0);
        } else {
            condition = (intArg1 > intArg2);
        }
    } else if (strcmp(op, "<") == 0) {
        if (!compInt) {
            condition = (strcmp(arg1.c_str(), arg2.c_str()) < 0);
        } else {
            condition = (intArg1 < intArg2);
        }
    } else if (strcmp(op, ">=") == 0) {
        if (!compInt) {
            condition = (strcmp(arg1.c_str(), arg2.c_str()) >= 0);
        } else {
            condition = (intArg1 >= intArg2);
        }
    } else if (strcmp(op, "<=") == 0) {
        if (!compInt) {
            condition = (strcmp(arg1.c_str(), arg2.c_str()) <= 0);
        } else {
            condition = (intArg1 <= intArg2);
        }
    } else {
        return "Invalid operator";
    }

    // Handle branching
    if (condition) {
        lexer.setTokens(thenTokens);
    } else if (hasElse) {
        lexer.setTokens(elseTokens);
    }

    ActionType actionType = lexer.executeTokens();
    toReturn = lexer.ExecuteCommand(actionType);
    return toReturn;
}