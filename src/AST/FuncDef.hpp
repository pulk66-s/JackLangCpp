#ifndef __JL_AST_FUNCDEF_HPP__
    #define __JL_AST_FUNCDEF_HPP__

    #include "ASTNamespace.hpp"
    #include "AST/Expr.hpp"
    #include "VarName.hpp"
    #include "LLVM.hpp"

    #include <memory>
    #include <vector>

namespace JL::AST {
    class FuncDef : public Expr {
        private:
            std::unique_ptr<VarName> name;
            std::vector<std::unique_ptr<VarName>> args;
            std::vector<std::unique_ptr<Expr>> body;

            void generateArgument(struct JL::LLVM::llvm_context llvm, llvm::Argument *arg, std::string name);

        public:
            FuncDef(std::unique_ptr<VarName> name, std::vector<std::unique_ptr<VarName>> args, std::vector<std::unique_ptr<Expr>> body);
            void print(std::ostream& os) const;
            bool operator==(const Expr &other) const;
            std::unique_ptr<LLVM::Operand> gen(struct JL::LLVM::llvm_context llvm);
    };
};

#endif