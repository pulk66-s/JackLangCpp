#ifndef __JL_PARSER_AST_VAR_HPP__
    #define __JL_PARSER_AST_VAR_HPP__

    #include "ParserNamespace.hpp"
    #include "LLVM.hpp"
    #include "Type.hpp"
    #include "AST/Expr.hpp"
    #include <string>

namespace JL::AST {
    class VarName : public Expr {
    private:
        std::string name;
    
    public:
        VarName(std::string name);
        void print(std::ostream& os) const;
        bool operator==(const Expr& other) const;
        bool operator==(std::string name) const;
        std::unique_ptr<LLVM::Operand> gen(struct JL::LLVM::llvm_context llvm);
        std::string getName() const;
    };
}

#endif