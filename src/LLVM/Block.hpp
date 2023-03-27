#ifndef __JL_LLVM_BLOCK_HPP__
    #define __JL_LLVM_BLOCK_HPP__

    #include "llvm/IR/Module.h"
    #include "Context.hpp"
    #include "IRBuilder.hpp"
    #include "Function.hpp"
    #include "NamedInstruction.hpp"
    #include <memory>

namespace JL::LLVM {
    class Block {
        private:
            llvm::BasicBlock *block = nullptr;

        public:
            Block(Context ctx, std::string name, std::unique_ptr<Function> func);
            Block(llvm::BasicBlock *block);

            // void addInstruction(std::unique_ptr<NamedInstruction> instruction);
            llvm::BasicBlock *get() const;
    };
};

#endif