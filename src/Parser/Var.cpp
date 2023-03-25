#include "Var.hpp"

namespace JL::Parser {
    std::unique_ptr<AST::Var> Var::parse(Token &token)
    {
        std::size_t tpos = token.save();
        Many::parse(token, Space::parse);
        std::cout << token.getRest() << std::endl;
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
            token.abort("Expected variable name", tpos);
        return std::make_unique<AST::Var>(name);
    }
};