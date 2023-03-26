#include "FuncCall.hpp"

namespace JL::Parser {
    std::unique_ptr<AST::Expr> FuncCall::parseArg(Token &token)
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
        for (auto parser : parsers) {
            try {
                return parser();
            } catch (Error::Parse &e) {
                continue;
            }
        }
        token.abort("Expected Line", tpos);
        return nullptr; // never reached
    }

    std::unique_ptr<AST::FuncCall> FuncCall::parse(Token &token)
    {
        std::size_t tpos = token.save();
        Many::parse(token, Space::parse);
        std::unique_ptr<AST::VarName> name = nullptr;
        try {
            name = VarName::parse(token);
        } catch (Error::Parse &e) {
            token.abort(e.what(), tpos);
        }
        Many::parse(token, Space::parse);
        try {
            token.expect('(');
        } catch (Error::Parse &e) {
            token.abort(e.what(), tpos);
        }
        Many::parse(token, Space::parse);
        std::vector<std::unique_ptr<AST::Expr>> args = {};
        try {
            while (true) {
                std::unique_ptr<AST::Expr> expr = FuncCall::parseArg(token);
                args.push_back(std::move(expr));
                Many::parse(token, Space::parse);
                token.expect(',');
                Many::parse(token, Space::parse);
            }
        } catch (Error::Parse &e) {}
        try {
            token.expect(')');
        } catch (Error::Parse &e) {
            token.abort(e.what(), ')');
        }
        return std::make_unique<AST::FuncCall>(std::move(name), std::move(args));
    }
};