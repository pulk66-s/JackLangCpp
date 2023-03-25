#ifndef __JL_PARSER_AST_EXPR_HPP__
    #define __JL_PARSER_AST_EXPR_HPP__

    #include "ParserNamespace.hpp"
    #include <iostream>

namespace JL::AST {
    class Expr {
    public:
        virtual ~Expr() = default;
        virtual void print(std::ostream& os) const = 0;
        friend std::ostream& operator<<(std::ostream& os, const Expr& expr) {
            expr.print(os);
            return os;
        }
        virtual bool operator==(const Expr& other) const = 0;
    };
}

#endif