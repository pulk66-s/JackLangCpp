#include "VarName.hpp"

namespace JL::AST {
    VarName::VarName(std::string name)
    {
        this->name = name;
    }

    void VarName::print(std::ostream& os) const
    {
        os << "VarName(" << name << ")";
    }

    bool VarName::operator==(const Expr& other) const
    {
        if (auto otherVar = dynamic_cast<const VarName*>(&other)) {
            return name == otherVar->name;
        }
        return false;
    }

    bool VarName::operator==(std::string name) const
    {
        return this->name == name;
    }

    std::unique_ptr<LLVM::Operand> VarName::gen(struct JL::LLVM::llvm_context llvm)
    {
        // TODO
    }

    std::string VarName::getName() const
    {
        return name;
    }
}