#ifndef __JL_PARSER_AST_NUM_HPP__
    #define __JL_PARSER_AST_NUM_HPP__

    #include "ParserNamespace.hpp"
    #include "AST/Expr.hpp"
    #include <string>
    #include <sstream>
    #include <iostream>

namespace JL::AST {
    class Num : public Expr {
    private:
        double value = 0;
    
    public:
        Num(double value): value(value) {};
        Num(std::string value) {
            std::stringstream ss(value);
            ss >> this->value;
        }

        void print(std::ostream& os) const override {
            os << "Num(" << this->value << ")";
        }
    };
}


#endif