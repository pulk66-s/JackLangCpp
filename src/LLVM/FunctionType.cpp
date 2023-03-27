#include "FunctionType.hpp"

namespace JL::LLVM {
    FunctionType::FunctionType(std::unique_ptr<LLVM::Type> retType, std::vector<std::unique_ptr<LLVM::Type>> args)
    {
        std::vector<llvm::Type *> llvmArgs;
        for (auto &arg : args) {
            llvmArgs.push_back(arg->get());
        }
        this->type = llvm::FunctionType::get(retType->get(), llvmArgs, false);
    }

    llvm::FunctionType *FunctionType::get()
    {
        return this->type;
    }
}