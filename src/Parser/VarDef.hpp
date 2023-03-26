#ifndef __JL_PARSER_VARDEF_HPP__
    #define __JL_PARSER_VARDEF_HPP__

    #include <memory>
    #include "AST.hpp"
    #include "Expr.hpp"
    #include "Many.hpp"
    #include "Space.hpp"
    #include "VarName.hpp"
    #include "Token.hpp"

namespace JL::Parser {
    class VarDef {
        public:
            static std::unique_ptr<AST::VarDef> parse(Token& token);
            static std::unique_ptr<AST::Expr> parseValue(Token &token);
    };
};

#endif