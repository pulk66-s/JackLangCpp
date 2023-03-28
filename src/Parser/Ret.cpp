#include "Ret.hpp"

namespace JL::Parser {
    std::unique_ptr<AST::Expr> Ret::parseExpr(Token &token)
    {
        std::size_t tpos = token.save();
        std::vector<std::function<std::unique_ptr<AST::Expr>()>> parsers = {
            [&]() -> std::unique_ptr<AST::Expr> {
                return FuncCall::parse(token);
            },
            [&]() -> std::unique_ptr<AST::Expr> {
                return Binop::parse(token);
            },
            [&]() -> std::unique_ptr<AST::Expr> {
                return Num::parse(token);
            },
            [&]() -> std::unique_ptr<AST::Expr> {
                return VarName::parse(token);
            }
        };
        int i = 0;
        for (auto parser : parsers) {
            try {
                std::cout << "i: " << i++ << std::endl;
                return parser();
            } catch (Error::Parse &e) {
                continue;
            }
        }
        token.abort("Expected Line", tpos);
        return nullptr; // never reached
    }

    std::unique_ptr<AST::Ret> Ret::parse(Token &token)
    {
        std::size_t tpos = token.save();
        Many::parse(token, Space::parse);
        token.expect("return");
        std::unique_ptr<AST::Expr> expr = Ret::parseExpr(token);
        return std::make_unique<AST::Ret>(std::move(expr));
    }
};