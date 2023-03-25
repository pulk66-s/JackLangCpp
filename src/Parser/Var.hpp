#ifndef __JL_PARSER_VAR_HPP__
    #define __JL_PARSER_VAR_HPP__

    #include "ParserNamespace.hpp"
    #include "AST.hpp"
    #include "Token.hpp"
    #include "Many.hpp"
    #include "Space.hpp"
    #include <memory>

namespace JL::Parser {
    class Var {
    public:
        static std::unique_ptr<AST::Var> parse(Token &token);
    };
};

#endif