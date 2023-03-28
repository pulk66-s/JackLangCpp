#include "FuncDef.hpp"

namespace JL::Parser {
    std::unique_ptr<AST::FuncDef> FuncDef::parse(Token &token)
    {
        std::size_t tpos = token.save();
        std::unique_ptr<AST::Type> type = nullptr;
        std::unique_ptr<AST::VarName> name = nullptr;
        std::vector<std::unique_ptr<AST::VarName>> args = {};
        std::vector<std::unique_ptr<AST::Expr>> body = {};

        Many::parse(token, Space::parse);
        try {
            std::cout << "Parsing function return type" << std::endl;
            type = Type::parse(token);
        } catch (Error::Parse &e) {
            std::cerr << e.what() << std::endl;
            token.abort("Expected function return type", tpos);
        }

        Many::parse(token, Space::parse);
        try {
            std::cout << "Parsing function name" << std::endl;
            name = VarName::parse(token);
        } catch (Error::Parse &e) {
            std::cerr << e.what() << std::endl;
            token.abort("Expected function name", tpos);
        }

        Many::parse(token, Space::parse);
        try {
            token.expect('(');
        } catch (Error::Parse &e) {
            token.abort(e.what(), tpos);
        }

        Many::parse(token, Space::parse);
        try {
            std::cout << "Parsing function arguments" << std::endl;
            while (true) {
                args.push_back(VarName::parse(token));
                Many::parse(token, Space::parse);
                token.expect(',');
                Many::parse(token, Space::parse);
            }
        } catch (Error::Parse &e) {}

        Many::parse(token, Space::parse);
        try {
            token.expect(')');
            Many::parse(token, Space::parse);
            token.expect('{');
            Many::parse(token, Space::parse);
        } catch (Error::Parse &e) {
            token.abort(e.what(), tpos);
        }

        Many::parse(token, Space::parse);
        try {
            std::cout << "Parsing function body" << std::endl;
            body = Many::parse(token, Expr::parse);
            Many::parse(token, Space::parse);
        } catch (Error::Parse &e) {
            std::cerr << e.what() << std::endl;
            token.abort("Expected function body", tpos);
        }

        Many::parse(token, Space::parse);
        try {
            token.expect('}');
        } catch (Error::Parse &e) {
            token.abort("Expected }", tpos);
        }
        std::cout << "Parsed function" << std::endl;
        return std::make_unique<AST::FuncDef>(std::move(name), std::move(args), std::move(body));
    }
};