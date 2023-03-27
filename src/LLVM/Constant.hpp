#ifndef __JL_LLVM_CONSTANT_HPP__
    #define __JL_LLVM_CONSTANT_HPP__

    #include "LLVMNamespace.hpp"
    #include "llvm.hpp"
    #include "IRBuilder.hpp"
    #include "Type.hpp"
    #include "llvm/IR/Module.h"
    #include "llvm/IR/IRBuilder.h"
    #include "Types/Int.hpp"
    #include "Operand.hpp"

namespace JL::LLVM {
    class Constant : public Operand {
        private:
            std::shared_ptr<Type> type;

        public:
            Constant(struct JL::LLVM::llvm_context llvm, std::shared_ptr<Types::Int> type, int value);

            std::shared_ptr<Type> getType();
    };
};

#endif