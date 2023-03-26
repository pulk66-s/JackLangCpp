#ifndef __JL_AST_CHAR_HPP__
    #define __JL_AST_CHAR_HPP__

    #include "ASTNamespace.hpp"
    #include "Expr.hpp"
    #include "LLVM.hpp"
    #include <iostream>

namespace JL::AST {
    class Char : public Expr {
        private:
            char value;

        public:
            Char(char value);
            void print(std::ostream& os) const;
            bool operator==(const Expr& other) const;
            void gen(struct llvm_context llvm);
    };
};

#endif