#include "Load.hpp"

namespace JL::LLVM {
    Load::Load(struct llvm_context llvm, std::unique_ptr<Operand> target, std::unique_ptr<Operand> ptr)
    {
        llvm::IRBuilder<> *builder = llvm.builder->get();
        std::unique_ptr<Types::Int> t = std::make_unique<Types::Int>(*(llvm.context));
        this->ptr = builder->CreateLoad(t->get(), ptr->get());
    }

    std::unique_ptr<Operand> Load::get()
    {
        return std::make_unique<Operand>(ptr);
    }
}