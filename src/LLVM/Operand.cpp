#include "Operand.hpp"

namespace JL::LLVM {
    llvm::Value *Operand::get()
    {
        return this->value;
    }

    Operand::Operand(llvm::Value *value)
    {
        this->value = value;
    }
};
