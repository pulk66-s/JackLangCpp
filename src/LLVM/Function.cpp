#include "Function.hpp"

namespace JL::LLVM {
    Function::Function(FunctionType type, std::string name, Module module)
    {
        this->func = llvm::Function::Create(type.get(), llvm::Function::ExternalLinkage, name, module.get());
    }
};