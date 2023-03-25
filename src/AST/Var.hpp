#ifndef __JL_PARSER_AST_VAR_HPP__
    #define __JL_PARSER_AST_VAR_HPP__

    #include "ParserNamespace.hpp"
    #include "AST/Expr.hpp"

    #include <string>

namespace JL::AST {
    class Var : public Expr {
    private:
        std::string name;
    
    public:
        Var(std::string name): name(name) {}
        void print(std::ostream& os) const override {
            os << "Var(" << name << ")";
        }
        bool operator==(const Expr& other) const override {
            if (auto otherVar = dynamic_cast<const Var*>(&other)) {
                return name == otherVar->name;
            }
            return false;
        }
        bool operator==(std::string name) const {
            return this->name == name;
        }
    };
}

#endif