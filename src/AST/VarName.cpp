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

    void VarName::gen(struct llvm_context llvm)
    {
        // TODO
    }
}