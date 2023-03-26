#include "Int.hpp"

namespace JL::LLVM::Types {
    Int::Int(Context ctx)
    {
        this->type = llvm::Type::getInt32Ty(*ctx.get());
        this->name = "int";
    }
}