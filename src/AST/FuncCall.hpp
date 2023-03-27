#ifndef __JL_AST_FUNCCALL_HPP__
    #define __JL_AST_FUNCCALL_HPP__

    #include "ASTNamespace.hpp"
    #include "Expr.hpp"
    #include "VarName.hpp"
    #include "LLVM.hpp"

    #include <memory>
    #include <vector>

namespace JL::AST {
    class FuncCall : public Expr {
        private:
            std::unique_ptr<VarName> name;
            std::vector<std::unique_ptr<Expr>> args;

        public:
            FuncCall(std::unique_ptr<VarName> name, std::vector<std::unique_ptr<Expr>> args);
            void print(std::ostream& os) const;
            bool operator==(const Expr &other) const;
            std::unique_ptr<LLVM::Operand> gen(struct JL::LLVM::llvm_context llvm);
    };
};

#endif