#ifndef __JL_LLVM_OPERAND_HPP__
    #define __JL_LLVM_OPERAND_HPP__

    #include "LLVMNamespace.hpp"
    #include "llvm/IR/IRBuilder.h"
    #include "llvm/IR/Module.h"

namespace JL::LLVM {
    class Operand {
        protected:
            llvm::Value *value;

        public:
            Operand(llvm::Value *value = nullptr);
            llvm::Value *get();
    };
};

#endif
