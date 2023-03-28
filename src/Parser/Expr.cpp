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
        // int i = 0;
        for (auto parser : parsers) {
            try {
                // std::cout << "i: " << i++ << std::endl;
                return parser();
            } catch (Error::Parse &e) {
                continue;
            }
        }
        std::cout << "tok: " << token.getRest() << std::endl;
        token.abort("Expected expression 1", tpos);
        return nullptr; // Never reached
    }
};
    