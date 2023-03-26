#include "Either.hpp"

namespace JL::Parser {
    std::unique_ptr<AST::Expr> Either::either(
        Token &token, 
        std::function<std::unique_ptr<AST::Expr>(Token &)> parser1,
        std::function<std::unique_ptr<AST::Expr>(Token &)> parser2
    )
    {
        try {
            std::unique_ptr<AST::Expr> expr1 = parser1(token);
            return expr1;
        } catch(Error::Parse &e) {}
        try {
            std::unique_ptr<AST::Expr> expr2 = parser2(token);
            return expr2;
        } catch (Error::Parse &e) {}
        throw Error::Parse("Either::either");
        return nullptr;
    }
}