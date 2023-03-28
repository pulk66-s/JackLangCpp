#include "Function.hpp"
#include <iostream>

namespace JL::LLVM {
    Function::Function(FunctionType type, std::string name, Module module)
    {
        this->func = llvm::Function::Create(type.get(), llvm::Function::ExternalLinkage, name, module.get());
    }

    Function::Function(llvm::Function *func)
    {
        this->func = func;
    }

    llvm::Function *Function::get()
    {
        return this->func;
    }

    std::vector<llvm::Argument *> Function::getArguments()
    {
        if (!this->func)
            std::cerr << "plop1" << std::endl;
        if (this->func->arg_empty())
            std::cerr << "plop" << std::endl;
        std::vector<llvm::Argument *> args;
        for (auto &arg : this->func->args()) {
            args.push_back(&arg);
        }
        return args;
    }
};