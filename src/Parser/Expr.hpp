#ifndef __JL_PARSER_EXPR_HPP__
    #define __JL_PARSER_EXPR_HPP__

    #include <memory>
    #include <string>
    #include "ParserNamespace.hpp"
    #include "Token.hpp"
    #include "Num.hpp"
    #include "VarDef.hpp"
    #include "FuncDef.hpp"
    #include "VarName.hpp"
    #include "Line.hpp"
    #include "Binop.hpp"
    #include "AST/Expr.hpp"

namespace JL::Parser {
    class Expr {
        public:
            static std::unique_ptr<AST::Expr> parse(Token &token);
    };
};

#endif