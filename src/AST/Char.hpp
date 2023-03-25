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
            bool operator==(const Expr& other) const {
                if (const Char* num = dynamic_cast<const Char*>(&other)) {
                    return *this == *num;
                }
                return false;
            }
    };
};

#endif