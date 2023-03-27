#ifndef __JL_AST_LINE_HPP__
    #define __JL_AST_LINE_HPP__

    #include "Expr.hpp"
    #include "LLVM.hpp"
    #include "ASTNamespace.hpp"
    #include <memory>
    #include <iostream>

namespace JL::AST {
    class Line : public Expr {
        private:
            std::unique_ptr<Expr> expr = nullptr;
        
        public:
            Line(std::unique_ptr<Expr> expr);
            void print(std::ostream &os) const;
            bool operator==(const Expr &other) const;
            std::unique_ptr<LLVM::Operand> gen(struct JL::LLVM::llvm_context llvm);
    };
};

#endif