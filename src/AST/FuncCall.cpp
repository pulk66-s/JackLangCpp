#include "FuncCall.hpp"

namespace JL::AST {
    FuncCall::FuncCall(std::unique_ptr<VarName> name, std::vector<std::unique_ptr<Expr>> args)
    {
        this->name = std::move(name);
        this->args = std::move(args);
    }

    void FuncCall::print(std::ostream& os) const
    {
        os << "FuncCall(";
        name->print(os);
        os << ", [";
        for (auto& arg : args) {
            arg->print(os);
            os << ", ";
        }
        os << "])";
    }

    bool FuncCall::operator==(const Expr &other) const
    {
        if (auto otherFuncCall = dynamic_cast<const FuncCall *>(&other)) {
            return *this->name == *otherFuncCall->name && this->args == otherFuncCall->args;
        }
        return false;
    }

    void FuncCall::gen(struct llvm_context llvm)
    {
        // TODO
    }
};