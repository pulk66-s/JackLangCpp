#ifndef __JL_AST_VARDEF_HPP__
    #define __JL_AST_VARDEF_HPP__

    #include "ASTNamespace.hpp"
    #include "Expr.hpp"
    #include "VarName.hpp"

    #include <memory>

namespace JL::AST {
    class VarDef : public Expr {
        private:
            std::unique_ptr<VarName> name;
            std::unique_ptr<Expr> value;

        public:
            VarDef(std::unique_ptr<VarName> name, std::unique_ptr<Expr> value):
                name(std::move(name)), value(std::move(value)) {}
            void print(std::ostream& os) const override {
                os << "VarDef(";
                name->print(os);
                os << ", ";
                value->print(os);
                os << ")";
            }
            bool operator==(const Expr& other) const override {
                if (auto otherVarDef = dynamic_cast<const VarDef*>(&other)) {
                    return *name == *otherVarDef->name && *value == *otherVarDef->value;
                }
                return false;
            }
    };
};

#endif