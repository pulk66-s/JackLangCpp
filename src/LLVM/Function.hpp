#ifndef __JL_LLVM_FUNCTION_HPP__
    #define __JL_LLVM_FUNCTION_HPP__

    #include "LLVMNamespace.hpp"
    #include "llvm/IR/IRBuilder.h"
    #include "llvm/IR/Module.h"
    #include "LLVM/FunctionType.hpp"
    #include "LLVM/Module.hpp"
    #include "IRBuilder.hpp"
    #include <memory>

namespace JL::LLVM {
    class Function {
        private:
            llvm::Function *func = nullptr;

        public:
            Function(FunctionType type, std::string name, Module module);
    };
};

#endif