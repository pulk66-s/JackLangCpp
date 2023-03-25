#ifndef __JL_PARSER_EXPR_HPP__
    #define __JL_PARSER_EXPR_HPP__

    #include <memory>
    #include <string>
    #include "ParserNamespace.hpp"
    #include "Token.hpp"
    #include "Num.hpp"

namespace JL::Parser {
    class Expr {
        public:
            static std::unique_ptr<AST::Expr> parse(Token &token);
    };
};

#endif