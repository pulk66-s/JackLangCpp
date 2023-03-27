#include "VarDef.hpp"

namespace JL::AST {
    VarDef::VarDef(std::unique_ptr<VarName> name, std::unique_ptr<Expr> value)
    {
        this->name = std::move(name);
        this->value = std::move(value);
    }

    void VarDef::print(std::ostream& os) const
    {
        os << "VarDef(";
        name->print(os);
        os << ", ";
        value->print(os);
        os << ")";
    }

    bool VarDef::operator==(const Expr& other) const
    {
        if (auto otherVarDef = dynamic_cast<const VarDef*>(&other)) {
            return *name == *otherVarDef->name && *value == *otherVarDef->value;
        }
        return false;
    }

    std::unique_ptr<LLVM::Operand> VarDef::gen(struct JL::LLVM::llvm_context llvm)
    {
        std::string name = this->name->getName();
        std::unique_ptr<LLVM::Operand> value = this->value->gen(llvm);
        std::unique_ptr<LLVM::Alloca> alloca = std::make_unique<LLVM::Alloca>(llvm, std::move(value));
        return nullptr;
    }
};