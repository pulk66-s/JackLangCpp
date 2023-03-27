#ifndef __JL_LLVM_MODULE_HPP__
    #define __JL_LLVM_MODULE_HPP__

    #include "LLVMNamespace.hpp"
    #include "llvm/IR/IRBuilder.h"
    #include "llvm/IR/Module.h"
    #include "Context.hpp"
    #include <memory>
    #include <string>

namespace JL::LLVM {
    class Module {
        private:
            std::string name = "";
            std::shared_ptr<llvm::Module> mod;

        public:
            Module(std::string name, Context ctx);

            void print() const;

            llvm::Module *get();
    };
};

#endif