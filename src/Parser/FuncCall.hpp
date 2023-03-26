#ifndef __JL_PARSER_FUNCCALL_HPP__
    #define __JL_PARSER_FUNCCALL_HPP__

    #include <memory>
    #include "ParserNamespace.hpp"
    #include "AST.hpp"
    #include "Token.hpp"
    #include "Many.hpp"
    #include "Binop.hpp"
    #include "Num.hpp"
    #include "Space.hpp"
    #include "VarName.hpp"
    #include "Error/Parse.hpp"

namespace JL::Parser {
    class FuncCall {
        public:
            static std::unique_ptr<AST::FuncCall> parse(Token &token);
            static std::unique_ptr<AST::Expr> parseArg(Token &token);
    };
};

#endif