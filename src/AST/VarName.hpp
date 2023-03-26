#ifndef __JL_PARSER_AST_VAR_HPP__
    #define __JL_PARSER_AST_VAR_HPP__

    #include "ParserNamespace.hpp"
    #include "LLVM.hpp"
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
        void gen(struct llvm_context llvm);
    };
}

#endif