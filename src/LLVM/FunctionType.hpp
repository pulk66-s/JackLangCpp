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
            FunctionType(std::unique_ptr<LLVM::Type> retType, std::vector<std::unique_ptr<LLVM::Type>> args);

            llvm::FunctionType *get();
    };
}

#endif