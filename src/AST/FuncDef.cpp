#include "FuncDef.hpp"

namespace JL::AST {
    FuncDef::FuncDef(
        std::unique_ptr<VarName> name,
        std::vector<std::unique_ptr<VarName>> args,
        std::vector<std::unique_ptr<Expr>> body
    )
    {
        this->name = std::move(name);
        this->args = std::move(args);
        this->body = std::move(body);
    }

    void FuncDef::print(std::ostream& os) const
    {
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

    bool FuncDef::operator==(const Expr &other) const
    {
        if (auto otherFunc = dynamic_cast<const FuncDef*>(&other)) {
            return *name == *otherFunc->name
                && args == otherFunc->args
                && body == otherFunc->body;
        }
        return false;
    }

    void FuncDef::gen(struct llvm_context llvm)
    {
        // TODO
    }
};