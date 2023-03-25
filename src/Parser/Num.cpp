#include "Num.hpp"

namespace JL::Parser {
    std::unique_ptr<AST::Num> Num::parse(Token &token)
    {
        char c = token.getToken();
        std::string value = "";

        while (c >= '0' && c <= '9') {
            value += c;
            token.nextToken();
            c = token.getToken();
        }
        return std::make_unique<AST::Num>(value);
    }
};

