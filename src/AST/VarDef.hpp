#ifndef __JL_AST_VARDEF_HPP__
    #define __JL_AST_VARDEF_HPP__

    #include "ASTNamespace.hpp"
    #include "Expr.hpp"
    #include "VarName.hpp"
    #include "LLVM.hpp"

    #include <memory>

namespace JL::AST {
    class VarDef : public Expr {
        private:
            std::unique_ptr<VarName> name;
            std::unique_ptr<Expr> value;

        public:
            VarDef(std::unique_ptr<VarName> name, std::unique_ptr<Expr> value);
            void print(std::ostream& os) const;
            bool operator==(const Expr& other) const;
            std::unique_ptr<LLVM::Operand> gen(struct JL::LLVM::llvm_context llvm);
    };
};

#endif