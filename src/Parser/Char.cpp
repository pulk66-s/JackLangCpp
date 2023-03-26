#include "Char.hpp"

namespace JL::Parser {
    std::unique_ptr<AST::Char> Char::parse(Token &token, char c)
    {
        token.expect(c);
        return std::make_unique<AST::Char>(c);
    }
};