#include "FuncDef.hpp"

namespace JL::Parser {
    std::unique_ptr<AST::FuncDef> FuncDef::parse(Token &token)
    {
        std::size_t tpos = token.save();
        Many::parse(token, Space::parse);
        std::unique_ptr<AST::VarName> name = nullptr;
        try {
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
        std::vector<std::unique_ptr<AST::VarName>> args = {};
        try {
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
        std::vector<std::unique_ptr<AST::Expr>> body = {};
        try {
            body = Many::parse(token, Expr::parse);
            Many::parse(token, Space::parse);
        } catch (Error::Parse &e) {
            std::cerr << e.what() << std::endl;
            token.abort("Expected function body", tpos);
        }
        try {
            token.expect('}');
        } catch (Error::Parse &e) {
            token.abort("Expected }", tpos);
        }
        return std::make_unique<AST::FuncDef>(std::move(name), std::move(args), std::move(body));
    }
};