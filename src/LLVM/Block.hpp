#ifndef __JL_LLVM_BLOCK_HPP__
    #define __JL_LLVM_BLOCK_HPP__

    #include "llvm/IR/Module.h"
    #include <memory>

namespace JL::LLVM {
    class Block {
        private:
            std::unique_ptr<llvm::BasicBlock> block = nullptr;

        public:
            Block();
    };
};

#endif