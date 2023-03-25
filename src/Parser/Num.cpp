#include "Num.hpp"

namespace JL::Parser {
    std::unique_ptr<AST::Num> Num::parse(Token &token)
    {
        char c = token.getToken();
        std::string value = "";

        if (c == '-') {
            value += c;
            token.nextToken();
            c = token.getToken();
        }
        while (c >= '0' && c <= '9') {
            value += c;
            token.nextToken();
            c = token.getToken();
        }
        if (value == "" || value == "-")
            throw Error::Parse("Expected number, got '" + std::string(1, c) + "'");
        return std::make_unique<AST::Num>(value);
    }
};

