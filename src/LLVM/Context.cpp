#include "Context.hpp"

namespace JL::LLVM {
    Context::Context()
    {
        this->context = std::make_shared<llvm::LLVMContext>();
    }

    llvm::LLVMContext *Context::get()
    {
        return this->context.get();
    }
}