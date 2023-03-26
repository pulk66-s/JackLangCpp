#ifndef __JL_LLVM_LLVM_HPP__
    #define __JL_LLVM_LLVM_HPP__

    #include "Context.hpp"
    #include "IRBuilder.hpp"
    #include "Module.hpp"
    #include <memory>

struct llvm_context {
    std::unique_ptr<JL::LLVM::Context> context;
    std::unique_ptr<JL::LLVM::IRBuilder> builder;
    std::unique_ptr<JL::LLVM::Module> mod;
};

#endif