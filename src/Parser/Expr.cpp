#include "Expr.hpp"

namespace JL::Parser {
    std::unique_ptr<AST::Expr> Expr::parse(Token &token)
    {
        return Num::parse(token);
    }
};

