#include "Operand.hpp"

namespace JL::LLVM {
    llvm::Value *Operand::get()
    {
        return this->value;
    }
};
