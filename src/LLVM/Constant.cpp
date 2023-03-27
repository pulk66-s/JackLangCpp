#include "Constant.hpp"

namespace JL::LLVM {
    Constant::Constant(struct JL::LLVM::llvm_context llvm, std::shared_ptr<Types::Int> type, int value)
    {
        std::shared_ptr<Context> ctx = llvm.context;
        this->type = type;
        this->value = llvm::ConstantInt::get(
            *ctx->get(),
            llvm::APInt(32, value)
        );
    }

    std::shared_ptr<Type> Constant::getType()
    {
        return this->type;
    }
};