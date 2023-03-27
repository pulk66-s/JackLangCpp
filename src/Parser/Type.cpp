#include "Type.hpp"

namespace JL::Parser {
    std::unique_ptr<AST::Type> Type::parse(Token &token)
    {
        std::size_t tpos = token.save();

        try {
            token.expect("int");
            return std::make_unique<AST::Type>("int");
        } catch (std::runtime_error &e) {}
        throw std::runtime_error("Expected type");
    }
};