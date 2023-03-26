#include "Char.hpp"

namespace JL::AST {
    Char::Char(char value)
    {
        this->value = value;
    }

    void Char::print(std::ostream& os) const
    {
        os << "Char(" << this->value << ")";
    }

    bool Char::operator==(const Expr& other) const
    {
        if (const Char* num = dynamic_cast<const Char*>(&other)) {
            return *this == *num;
        }
        return false;
    }

    void Char::gen(struct llvm_context llvm)
    {
        // TODO
    }
}