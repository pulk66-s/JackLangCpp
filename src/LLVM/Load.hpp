#ifndef __JL_LLVM_LOAD_HPP__
    #define __JL_LLVM_LOAD_HPP__

    #include "LLVMNamespace.hpp"
    #include "llvm.hpp"
    #include "llvm/IR/IRBuilder.h"
    #include "llvm/IR/Module.h"
    #include "Operand.hpp"
    #include "Types/Int.hpp"
    #include <memory>

namespace JL::LLVM {
    class Load {
        private:
            llvm::LoadInst *ptr;

        public:
            Load(struct llvm_context llvm, std::unique_ptr<Operand> target, std::unique_ptr<Operand> ptr);

            std::unique_ptr<Operand> get();
    };
};

#endif