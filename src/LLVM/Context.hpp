#ifndef __JL_LLVM_CONTEXT_HPP__
    #define __JL_LLVM_CONTEXT_HPP__

    #include <memory>
    #include "LLVMNamespace.hpp"
    #include "llvm/IR/Module.h"

namespace JL::LLVM {
    class Context {
        private:
            std::shared_ptr<llvm::LLVMContext> context;

        public:
            Context();
            llvm::LLVMContext *get();
    };
};

#endif