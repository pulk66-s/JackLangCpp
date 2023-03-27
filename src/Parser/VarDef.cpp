#include "VarDef.hpp"

namespace JL::Parser {
    std::unique_ptr<AST::Expr> VarDef::parseValue(Token &token)
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
        token.abort("Expected expression", tpos);
        return nullptr; // Never reached
    }

    std::unique_ptr<AST::VarDef> VarDef::parse(Token& token)
    {
        size_t tpos = token.save();
        std::unique_ptr<AST::Type> type = nullptr;
        std::unique_ptr<AST::VarName> name = nullptr;
        std::unique_ptr<AST::Expr> value = nullptr;

        Many::parse(token, Space::parse);
        try {
            type = Type::parse(token);
        } catch (Error::Parse &e) {
            token.abort("Expected type", tpos);
        }

        Many::parse(token, Space::parse);
        try {
            name = VarName::parse(token);
        } catch (Error::Parse &e) {
            token.abort("Expected variable name", tpos);
        }

        Many::parse(token, Space::parse);
        try {
            token.expect('=');
        } catch (Error::Parse &e) {
            token.abort(e.what(), tpos);
        }
        Many::parse(token, Space::parse);

        try {
            value = VarDef::parseValue(token);
        } catch (Error::Parse &e) {
            token.abort("Expected variable value", tpos);
        }
        return std::make_unique<AST::VarDef>(std::move(name), std::move(value));
    }
};