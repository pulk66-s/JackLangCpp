#include "Line.hpp"

namespace JL::Parser {
    std::unique_ptr<AST::Line> Line::parse(Token &token)
    {
        std::size_t tpos = token.save();
        std::vector<std::function<std::unique_ptr<AST::Expr>()>> parsers = {
            [&]() -> std::unique_ptr<AST::Expr> {
                return FuncCall::parse(token);
            },
            [&]() -> std::unique_ptr<AST::Expr> {
                return Ret::parse(token);
            },
            [&]() -> std::unique_ptr<AST::Expr> {
                return VarDef::parse(token);
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
        for (auto parser : parsers) {
            try {
                std::unique_ptr<AST::Expr> expr = parser();
                token.expect(';');
                return std::make_unique<AST::Line>(std::move(expr));
            } catch (Error::Parse &e) {
                continue;
            }
        }
        token.abort("Expected Line", tpos);
        return nullptr; // never reached
    }
};