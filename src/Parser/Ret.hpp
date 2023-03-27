#ifndef __JL_PARSER_RET_HPP__
    #define __JL_PARSER_RET_HPP__

    #include "ParserNamespace.hpp"
    #include "AST.hpp"
    #include "Token.hpp"
    #include "Expr.hpp"
    #include <memory>

namespace JL::Parser {
    class Ret {
        public:
            static std::unique_ptr<AST::Ret> parse(Token &token);
            static std::unique_ptr<AST::Expr> parseExpr(Token &token);
    };
};

#endif