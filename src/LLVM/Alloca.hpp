#ifndef __JL_LLVM_ALLOCA_HPP__
    #define __JL_LLVM_ALLOCA_HPP__

    #include "LLVMNamespace.hpp"
    #include "llvm.hpp"
    #include "llvm/IR/Module.h"
    #include "llvm/IR/IRBuilder.h"
    #include "Operand.hpp"
    #include <memory>
    #include <string>

namespace JL::LLVM {
    class Alloca {
        private:
            llvm::AllocaInst *llvmAlloca;

        public:
            Alloca(struct llvm_context llvm, std::unique_ptr<Operand> value, std::string name);
            llvm::AllocaInst *get();
    };
};

#endif