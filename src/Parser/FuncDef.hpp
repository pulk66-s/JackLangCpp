#ifndef __JL_PARSER_FUNCDEF_HPP__
    #define __JL_PARSER_FUNCDEF_HPP__

    #include "ParserNamespace.hpp"
    #include "AST.hpp"
    #include "Many.hpp"
    #include "Space.hpp"
    #include "VarName.hpp"
    #include "Error/Parse.hpp"
    #include "Token.hpp"
    #include "Char.hpp"
    #include "Either.hpp"
    #include <memory>

namespace JL::Parser {
    class FuncDef {
    public:
        static std::unique_ptr<AST::FuncDef> parse(Token& token);
    };
};

#endif