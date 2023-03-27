#include "Int.hpp"

namespace JL::LLVM::Types {
    Int::Int(Context ctx)
    : Type(llvm::Type::getInt32Ty(*ctx.get()))
    {
        this->name = "int";
    }

    bool Int::is(Type type)
    {
        return type.get()->isIntegerTy();
    }
}