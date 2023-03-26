#include "Type.hpp"

namespace JL::LLVM {
    llvm::Type *Type::get()
    {
        return this->type;
    }

    std::string Type::getName()
    {
        return this->name;
    }
};