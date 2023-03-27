#ifndef __JL_LLVM_OPERATION_HPP__
    #define __JL_LLVM_OPERATION_HPP__

    #include "LLVMNamespace.hpp"
    #include "IRBuilder.hpp"
    #include "LLVM/Constant.hpp"
    #include "Type.hpp"
    #include "Types/Int.hpp"
    #include "Error/NotImplemented.hpp"
    #include "llvm/IR/Module.h"
    #include "llvm/IR/IRBuilder.h"

namespace JL::LLVM {
    class Operation {
        private:
            llvm::Value *result = nullptr;

            void createIntOperation(IRBuilder builder, char op, Constant left, Constant right);

        public:
            Operation(IRBuilder builder, char op, Constant left, Constant right);
            // Operation(IRBuilder builder, char op, NamedInstruction left, NamedInstruction right);

            llvm::Value *get();
    };
};

#endif