#ifndef __JL_PARSER_AST_RET_HPP__
    #define __JL_PARSER_AST_RET_HPP__

    #include "ASTNamespace.hpp"
    #include "Expr.hpp"
    #include "LLVM.hpp"
    #include <memory>

namespace JL::AST {
    class Ret : public Expr {
        private:
            std::unique_ptr<Expr> expr;
        
        public:
            Ret(std::unique_ptr<Expr> expr);
            void print(std::ostream& os) const;
            bool operator==(const Expr& other) const;
            std::unique_ptr<LLVM::Operand> gen(struct JL::LLVM::llvm_context llvm);
    };
};

#endif