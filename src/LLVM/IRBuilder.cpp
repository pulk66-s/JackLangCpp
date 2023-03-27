#include "IRBuilder.hpp"

namespace JL::LLVM {
    IRBuilder::IRBuilder(Context ctx)
    {
        this->builder = std::make_shared<llvm::IRBuilder<>>(*ctx.get());
    }

    void IRBuilder::setInsertBlock(std::shared_ptr<Block> block)
    {
        this->builder->SetInsertPoint(block->get());
    }

    llvm::IRBuilder<> *IRBuilder::get()
    {
        return this->builder.get();
    }

    std::shared_ptr<Block> IRBuilder::getBlock()
    {
        llvm::BasicBlock *block = this->builder->GetInsertBlock();
        return std::make_shared<Block>(block);
    }
};