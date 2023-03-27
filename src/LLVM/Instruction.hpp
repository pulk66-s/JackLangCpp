#ifndef __JL_LLVM_INSTRUCTION_HPP__
    #define __JL_LLVM_INSTRUCTION_HPP__

    #include "LLVMNamespace.hpp"
    #include "llvm/IR/Instructions.h"
    #include "llvm/IR/Module.h"
    #include "Operand.hpp"
    #include "Type.hpp"

namespace JL::LLVM {
    class Instruction {
        protected:
            llvm::Instruction *llvmInstruction;

        public:
            Instruction(llvm::Instruction *llvmInstruction = nullptr);

            llvm::Instruction *get();
            std::unique_ptr<Type> getType();
    };
};

#endif