#include "Instruction.hpp"

namespace JL::LLVM {
    Instruction::Instruction(llvm::Instruction *llvmInstruction)
    {
        this->llvmInstruction = llvmInstruction;
    }

    llvm::Instruction *Instruction::get()
    {
        return this->llvmInstruction;
    }

    std::unique_ptr<Type> Instruction::getType()
    {
        if (this->llvmInstruction)
            return std::make_unique<Type>(this->llvmInstruction->getType());
        return nullptr;
    }
};
