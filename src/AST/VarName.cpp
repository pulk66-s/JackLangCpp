#include "VarName.hpp"

namespace JL::AST {
    VarName::VarName(std::string name, std::unique_ptr<Type> type)
    {
        this->type = std::move(type);
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
        std::cout << "VarName::gen " << this->name << std::endl;
        std::shared_ptr<LLVM::Operand> operand = llvm.nameGenerator->getOperand(name);
        if (operand == nullptr) {
            throw std::runtime_error("Variable " + name + " is not defined");
        }
        std::unique_ptr<LLVM::Operand> ptr = std::make_unique<LLVM::Operand>();
        std::unique_ptr<LLVM::Load> load = std::make_unique<LLVM::Load>(llvm, std::move(ptr), std::make_unique<LLVM::Operand>(*operand));
        return load->get();
    }

    std::string VarName::getName() const
    {
        return name;
    }
}