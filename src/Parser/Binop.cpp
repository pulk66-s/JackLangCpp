#include "Binop.hpp"

namespace JL::Parser {
    std::unique_ptr<AST::Expr> Binop::parseArg(Token &token)
    {
        std::vector<std::function<std::unique_ptr<AST::Expr>()>> parsers = {
            [&]() -> std::unique_ptr<AST::Expr> {
                return Num::parse(token);
            },
            [&]() -> std::unique_ptr<AST::Expr> {
                return Var::parse(token);
            }
        };
        for (auto parser : parsers) {
            try {
                return parser();
            } catch (Error::Parse &e) {
                continue;
            }
        }
        throw Error::Parse("Expected expression");
    }

    std::unique_ptr<AST::Binop> Binop::parse(Token &token)
    {
        std::unique_ptr<AST::Expr> lhs = Binop::parseArg(token);

        char op = token.getToken();
        token.nextToken();
        if (op != '+' && op != '-' && op != '*' && op != '/' && op != '%')
            throw Error::Parse("Expected operator");

        std::unique_ptr<AST::Expr> rhs = Binop::parseArg(token);

        return std::make_unique<AST::Binop>(op, std::move(lhs), std::move(rhs));
    }
};