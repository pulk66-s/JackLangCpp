#include "Parser.hpp"

namespace JL::Parser {
    Parser::Parser(std::string content)
    : token(content)
    {
    }

    std::unique_ptr<AST::Expr> Parser::launch()
    {
        return Expr::parse(this->token);
    }
};