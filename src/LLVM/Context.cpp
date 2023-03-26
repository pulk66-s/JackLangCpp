#include "Context.hpp"

namespace JL::LLVM {
    Context::Context()
    {
        this->context = std::make_shared<llvm::LLVMContext>();
    }

    std::shared_ptr<llvm::LLVMContext> Context::get()
    {
        return this->context;
    }
}