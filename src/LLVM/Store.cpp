#include "Store.hpp"
#include <iostream>

namespace JL::LLVM {
    Store::Store(struct llvm_context llvm, std::unique_ptr<Operand> value, std::unique_ptr<Operand> ptr)
    {
        if (!value || !ptr)
            std::cerr << "Error: Store instruction requires a value and a pointer" << std::endl;
        this->llvmStore = llvm.builder->get()->CreateStore(value->get(), ptr->get());
    }
};