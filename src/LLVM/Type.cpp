#include "Type.hpp"

namespace JL::LLVM {
    Type::Type(llvm::Type *type)
    {
        this->type = type;
    }

    llvm::Type *Type::get()
    {
        return this->type;
    }

    std::string Type::getName()
    {
        return this->name;
    }
};