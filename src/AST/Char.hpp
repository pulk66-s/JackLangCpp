#ifndef __JL_AST_CHAR_HPP__
    #define __JL_AST_CHAR_HPP__

    #include "ASTNamespace.hpp"
    #include "Expr.hpp"
    #include <iostream>

namespace JL::AST {
    class Char : public Expr {
        private:
            char value;

        public:
            Char(char value): value(value) {};
            void print(std::ostream& os) const {
                os << "Char(" << this->value << ")";
            }
    };
};

#endif