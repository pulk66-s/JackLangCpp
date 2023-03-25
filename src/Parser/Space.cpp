#include "Space.hpp"

namespace JL::Parser {
    std::unique_ptr<AST::Char> Space::parse(Token &token)
    {
        std::size_t tpos = token.save();
        char c = token.getToken();

        if (c == ' ' || c == '\t' || c == '\n') {
            token.nextToken();
            return std::make_unique<AST::Char>(c);
        }
        token.abort("Expected space", tpos);
        return nullptr; // Never reached
    }
};