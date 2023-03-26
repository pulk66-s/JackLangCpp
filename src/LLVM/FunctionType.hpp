#ifndef __JL_LLVM_FUNCTIONTYPE_HPP__
    #define __JL_LLVM_FUNCTIONTYPE_HPP__

    #include "LLVMNamespace.hpp"
    #include "LLVM/Type.hpp"
    #include "llvm/IR/Module.h"
    #include "llvm/IR/IRBuilder.h"
    #include <memory>
    #include <vector>

namespace JL::LLVM {
    class FunctionType {
        private:
            llvm::FunctionType *type = nullptr;

        public:
            FunctionType(LLVM::Type retType, std::vector<LLVM::Type> args);

            llvm::FunctionType *get();
    };
}

#endif