#ifndef __JL_AST_TYPE_HPP__
    #define __JL_AST_TYPE_HPP__

    #include "ASTNamespace.hpp"
    #include "Expr.hpp"

namespace JL::AST {
    class Type : public Expr {
        private:
            std::string type;
        
        public:
            Type(std::string type);
            void print(std::ostream& os) const;
            bool operator==(const Expr& other) const;
            std::unique_ptr<LLVM::Operand> gen(struct JL::LLVM::llvm_context llvm);
    };
};

#endif