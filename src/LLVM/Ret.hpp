#ifndef __JL_LLVM_RET_HPP__
    #define __JL_LLVM_RET_HPP__

    #include "llvm.hpp"
    #include "LLVMNamespace.hpp"
    #include "llvm/IR/Module.h"
    #include "llvm/IR/IRBuilder.h"
    #include "Operand.hpp"
    #include "Instruction.hpp"
    #include <memory>

namespace JL::LLVM {
    class Ret : public Instruction {
        private:
            llvm::ReturnInst *llvmRet;

        public:
            Ret(struct JL::LLVM::llvm_context llvm, std::unique_ptr<Operand> operand);
            llvm::ReturnInst *get();
    };
};

#endif