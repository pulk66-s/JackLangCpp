#include "Expr.hpp"

namespace JL::Parser {
    std::unique_ptr<AST::Expr> Expr::parse(Token &token)
    {
        std::size_t tpos = token.save();
        std::vector<std::function<std::unique_ptr<AST::Expr>()>> parsers = {
            [&]() -> std::unique_ptr<AST::Expr> {
                return FuncDef::parse(token);
            },
            [&]() -> std::unique_ptr<AST::Expr> {
                return Line::parse(token);
            }
        };
        for (auto parser : parsers) {
            try {
                return parser();
            } catch (Error::Parse &e) {
                continue;
            }
        }
        token.abort("Expected expression", tpos);
        return nullptr; // Never reached
    }
};
    