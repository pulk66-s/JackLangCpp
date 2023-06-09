#include "VarName.hpp"

namespace JL::Parser {
    std::unique_ptr<AST::VarName> VarName::parse(Token &token)
    {
        std::size_t tpos = token.save();
        std::unique_ptr<AST::Type> type = nullptr;
        try {
            type = Type::parse(token);
        } catch (const std::exception &e) {
            token.restore(tpos);
            type = nullptr;
        }
        Many::parse(token, Space::parse);
        std::string name = "";
        char c = token.getToken();

        while (
            (c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9')
            || c == '_'
        ) {
            name += c;
            token.nextToken();
            c = token.getToken();
        }
        if (name == "")
            token.abort("Expected variable name", tpos);
        return std::make_unique<AST::VarName>(name, std::move(type));
    }
};