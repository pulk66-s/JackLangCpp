#ifndef __JL_AST_FUNCDEF_HPP__
    #define __JL_AST_FUNCDEF_HPP__

    #include "ASTNamespace.hpp"
    #include "AST/Expr.hpp"
    #include "VarName.hpp"

    #include <memory>
    #include <vector>

namespace JL::AST {
    class FuncDef : public Expr {
        private:
            std::unique_ptr<VarName> name;
            std::vector<std::unique_ptr<VarName>> args;
            std::vector<std::unique_ptr<Expr>> body;

        public:
            FuncDef(std::unique_ptr<VarName> name, std::vector<std::unique_ptr<VarName>> args, std::vector<std::unique_ptr<Expr>> body):
                name(std::move(name)), args(std::move(args)), body(std::move(body)) {}
            void print(std::ostream& os) const override {
                os << "FuncDef(";
                name->print(os);
                os << ", [";
                for (auto& arg : args) {
                    arg->print(os);
                    os << ", ";
                }
                os << "], [";
                for (auto& expr : body) {
                    expr->print(os);
                    os << ", ";
                }
                os << "])";
            }
            bool operator==(const Expr &other) const {
                if (auto otherFuncDef = dynamic_cast<const FuncDef*>(&other)) {
                    return *name == *otherFuncDef->name && args == otherFuncDef->args && body == otherFuncDef->body;
                }
                return false;
            }
    };
};

#endif