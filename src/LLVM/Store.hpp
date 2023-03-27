#ifndef __JL_LLVM_STORE_HPP__
    #define __JL_LLVM_STORE_HPP__
 
    #include "LLVMNamespace.hpp"
    #include "Instruction.hpp"
    #include "Type.hpp"
    #include "Operand.hpp"
    #include "Alloca.hpp"
    #include "llvm.hpp"
    #include "llvm/IR/Module.h"
    #include "llvm/IR/IRBuilder.h"
 
    #include <memory>

namespace JL::LLVM {
    class Store {
        private:
            llvm::StoreInst *llvmStore;

        public:
            Store(struct llvm_context llvm, std::unique_ptr<Operand> value, std::unique_ptr<Operand> ptr);
    };
};

#endif