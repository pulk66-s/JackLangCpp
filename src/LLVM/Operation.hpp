#ifndef __JL_LLVM_OPERATION_HPP__
    #define __JL_LLVM_OPERATION_HPP__

    #include "LLVMNamespace.hpp"
    #include "llvm.hpp"
    #include "Error/NotImplemented.hpp"
    #include "llvm/IR/Module.h"
    #include "llvm/IR/IRBuilder.h"
    #include "Operand.hpp"
    #include <memory>

namespace JL::LLVM {
    class Operation : public Operand {
        private:
            void updateValue(struct llvm_context llvm, char op, std::unique_ptr<Operand> left, std::unique_ptr<Operand> right);

        public:
            Operation(struct llvm_context llvm, char op, std::unique_ptr<Operand> left, std::unique_ptr<Operand> right);
    };
};

#endif