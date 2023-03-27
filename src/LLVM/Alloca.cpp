#include "Alloca.hpp"
#include <iostream>

namespace JL::LLVM {
    Alloca::Alloca(struct llvm_context llvm, std::unique_ptr<Operand> value, std::string name)
    {
        this->llvmAlloca = llvm.builder->get()->CreateAlloca(value->get()->getType(), 0, name);
    }

    llvm::AllocaInst *Alloca::get()
    {
        return this->llvmAlloca;
    }
};