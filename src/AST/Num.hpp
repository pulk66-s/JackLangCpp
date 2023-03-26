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
        bool operator==(const Expr& other) const;
        bool operator==(double value) const;
        void gen(struct llvm_context llvm);
    };
}


#endif