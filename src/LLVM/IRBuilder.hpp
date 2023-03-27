#ifndef __JL_LLVM_IRBUILDER_HPP__
    #define __JL_LLVM_IRBUILDER_HPP__

    #include <memory>
    #include "Context.hpp"
    #include "Block.hpp"
    #include "Operand.hpp"
    #include "LLVMNamespace.hpp"
    #include "llvm/IR/IRBuilder.h"
    #include "llvm/IR/Module.h"

namespace JL::LLVM {
    class IRBuilder {
        private:
            std::shared_ptr<llvm::IRBuilder<>> builder = nullptr;

        public:
            IRBuilder(Context ctx);

            void setInsertBlock(std::shared_ptr<Block> block);
            std::shared_ptr<Block> getBlock();

            llvm::IRBuilder<> *get();
    };
};

#endif