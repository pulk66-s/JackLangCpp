#ifndef __JL_PARSER_AST_VAR_HPP__
    #define __JL_PARSER_AST_VAR_HPP__

    #include "ParserNamespace.hpp"
    #include "AST/Expr.hpp"

    #include <string>

namespace JL::AST {
    class Var : public Expr {
    private:
        std::string name;
    
    public:
        Var(std::string name): name(name) {}
    };
}

#endif