#include "Block.hpp"

namespace JL::LLVM {
    Block::Block(Context ctx, std::string name, std::unique_ptr<Function> func)
    {
        this->block = llvm::BasicBlock::Create(*ctx.get(), name, func->get());
    }

    Block::Block(llvm::BasicBlock *block)
    {
        this->block = block;
    }

    llvm::BasicBlock *Block::get() const
    {
        return this->block;
    }

    // void Block::addInstruction(std::unique_ptr<NamedInstruction> instruction)
    // {
    //     // this->block->getInstList().push_back(instruction->get());
    // }
};