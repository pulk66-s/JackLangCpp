#ifndef __JL_AST_FUNCCALL_HPP__
    #define __JL_AST_FUNCCALL_HPP__

    #include "ASTNamespace.hpp"
    #include "Expr.hpp"
    #include "VarName.hpp"

    #include <memory>
    #include <vector>

namespace JL::AST {
    class FuncCall : public Expr {
        private:
            std::unique_ptr<VarName> name;
            std::vector<std::unique_ptr<Expr>> args;

        public:
            FuncCall(std::unique_ptr<VarName> name, std::vector<std::unique_ptr<Expr>> args):
                name(std::move(name)), args(std::move(args)) {}
            void print(std::ostream& os) const override {
                os << "FuncCall(";
                name->print(os);
                os << ", [";
                for (auto& arg : args) {
                    arg->print(os);
                    os << ", ";
                }
                os << "])";
            }
            bool operator==(const Expr &other) const {
                if (auto otherFuncCall = dynamic_cast<const FuncCall *>(&other)) {
                    return *this->name == *otherFuncCall->name && this->args == otherFuncCall->args;
                }
                return false;
            }
    };
};

#endif