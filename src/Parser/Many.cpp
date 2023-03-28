#include "Many.hpp"

namespace JL::Parser {
    std::vector<std::unique_ptr<AST::Expr>> Many::parse(Token &token, std::function<std::unique_ptr<AST::Expr>(Token &)> parser) {
        std::vector<std::unique_ptr<AST::Expr>> exprs = {};

        while (true) {
            try {
                std::unique_ptr<AST::Expr> expr = parser(token);
                exprs.push_back(std::move(expr));
            } catch (Error::Parse &e) {
                break;
            }
        }
        return exprs;
    }
}