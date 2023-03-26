#include "IRBuilder.hpp"

namespace JL::LLVM {
    IRBuilder::IRBuilder(Context ctx)
    {
        this->builder = std::make_unique<llvm::IRBuilder<>>(*ctx.get());
    }
};