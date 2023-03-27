#include "Type.hpp"

namespace JL::AST {
    Type::Type(std::string type)
    {
        this->type = type;
    }

    void Type::print(std::ostream& os) const
    {
        os << "Type(" << this->type << ")";
    }

    bool Type::operator==(const Expr& other) const
    {
        if (const Type *otherType = dynamic_cast<const Type*>(&other))
            return this->type == otherType->type;
        return false;
    }

    std::unique_ptr<LLVM::Operand> Type::gen(struct JL::LLVM::llvm_context llvm)
    {
        return nullptr;
    }
};