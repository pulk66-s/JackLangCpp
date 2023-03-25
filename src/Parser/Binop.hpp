#ifndef __JL_PARSER_BINOP_HPP__
    #define __JL_PARSER_BINOP_HPP__

    #include "ParserNamespace.hpp"
    #include "AST.hpp"
    #include "Space.hpp"
    #include "Many.hpp"
    #include "Expr.hpp"
    #include <memory>

namespace JL::Parser {
    class Binop {
        public:
            static std::unique_ptr<AST::Binop> parse(Token &token);
            static std::unique_ptr<AST::Expr> parseLArg(Token &token);
            static std::unique_ptr<AST::Expr> parseRArg(Token &token);
    };
};

#endif