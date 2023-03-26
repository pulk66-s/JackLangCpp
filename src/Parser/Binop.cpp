#include "Binop.hpp"

namespace JL::Parser {
    std::unique_ptr<AST::Expr> Binop::parseLArg(Token &token)
    {
        std::size_t tpos = token.save();
        std::vector<std::function<std::unique_ptr<AST::Expr>()>> parsers = {
            [&]() -> std::unique_ptr<AST::Expr> {
                return Num::parse(token);
            },
            [&]() -> std::unique_ptr<AST::Expr> {
                return VarName::parse(token);
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

    std::unique_ptr<AST::Expr> Binop::parseRArg(Token &token)
    {
        std::size_t tpos = token.save();
        std::vector<std::function<std::unique_ptr<AST::Expr>()>> parsers = {
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
                return parser();
            } catch (Error::Parse &e) {
                continue;
            }
        }
        token.abort("Expected expression", tpos);
        return nullptr; // Never reached
    }

    std::unique_ptr<AST::Binop> Binop::parse(Token &token)
    {
        std::size_t tpos = token.save();
        std::unique_ptr<AST::Expr> lhs = Binop::parseLArg(token);
        Many::parse(token, Space::parse);
        char op = token.getToken();
        token.nextToken();
        if (op != '+' && op != '-' && op != '*' && op != '/' && op != '%')
            token.abort("Expected operator", tpos);
        Many::parse(token, Space::parse);
        std::unique_ptr<AST::Expr> rhs = Binop::parseRArg(token);
        return std::make_unique<AST::Binop>(op, std::move(lhs), std::move(rhs));
    }
};