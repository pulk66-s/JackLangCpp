#ifndef __JL_LLVM_TYPE_HPP__
    #define __JL_LLVM_TYPE_HPP__

    #include "llvm/IR/IRBuilder.h"
    #include "llvm/IR/Module.h"
    #include <memory>
    #include <string>

namespace JL::LLVM {
    class Type {
        protected:
            llvm::Type *type = nullptr;
            std::string name = "";

        public:
            llvm::Type *get();
            std::string getName();
    };
};

#endif