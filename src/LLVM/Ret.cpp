#include "Ret.hpp"

namespace JL::LLVM {
    Ret::Ret(struct JL::LLVM::llvm_context llvm, std::unique_ptr<Operand> operand)
    {
        std::shared_ptr<Context> ctx = llvm.context;
        std::shared_ptr<IRBuilder> builder = llvm.builder;
        this->llvmRet = builder->get()->CreateRet(operand->get());
    }

    llvm::ReturnInst *Ret::get()
    {
        return this->llvmRet;
    }
};