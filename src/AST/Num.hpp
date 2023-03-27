#ifndef __JL_PARSER_AST_NUM_HPP__
    #define __JL_PARSER_AST_NUM_HPP__

    #include "ParserNamespace.hpp"
    #include "AST/Expr.hpp"
    #include "LLVM.hpp"
    #include <string>
    #include <sstream>
    #include <iostream>

namespace JL::AST {
    class Num : public Expr {
    private:
        double value = 0;
    
    public:
        Num(double value);
        Num(std::string value);

        void print(std::ostream& os) const;
        std::unique_ptr<LLVM::Operand> gen(struct JL::LLVM::llvm_context llvm);
        static bool is(Expr *expr);

        bool operator==(const Expr& other) const;
        bool operator==(double value) const;

        double get() const;
    };
}


#endif