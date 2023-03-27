#include "Alloca.hpp"
#include <iostream>

namespace JL::LLVM {
    Alloca::Alloca(struct llvm_context llvm, std::unique_ptr<Operand> value)
    {
        this->llvmAlloca = llvm.builder->get()->CreateAlloca(value->get()->getType(), 0, "tmp");
    }
};