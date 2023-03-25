#include "Var.hpp"

namespace JL::Parser {
    std::unique_ptr<AST::Var> Var::parse(Token &token)
    {
        std::string name = "";
        char c = token.getToken();

        while (
            (c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9')
            || c == '_'
        ) {
            name += c;
            token.nextToken();
            c = token.getToken();
        }
        if (name == "")
            throw std::runtime_error("Expected variable name");
        return std::make_unique<AST::Var>(name);
    }
};