#ifndef __JL_LLVM_LLVM_HPP__
    #define __JL_LLVM_LLVM_HPP__

    #include "Context.hpp"
    #include "IRBuilder.hpp"
    #include "Module.hpp"
    #include "NameGenerator.hpp"
    #include <memory>

namespace JL::LLVM {
    struct llvm_context {
        std::shared_ptr<JL::LLVM::Context> context;
        std::shared_ptr<JL::LLVM::IRBuilder> builder;
        std::shared_ptr<JL::LLVM::Module> mod;
        std::shared_ptr<JL::LLVM::NameGenerator> nameGenerator;
    };
};

#endif