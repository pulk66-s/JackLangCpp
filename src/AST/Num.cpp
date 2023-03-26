#include "Num.hpp"

namespace JL::AST {
    Num::Num(double value)
    {
        this->value = value;
    }

    Num::Num(std::string value)
    {
        std::stringstream ss(value);
        ss >> this->value;
    }

    void Num::print(std::ostream& os) const
    {
        os << "Num(" << this->value << ")";
    }

    bool Num::operator==(const Expr& other) const
    {
        if (const Num* num = dynamic_cast<const Num*>(&other)) {
            return *this == *num;
        }
        return false;
    }

    bool Num::operator==(double value) const
    {
        return this->value == value;
    }

    void Num::gen(struct llvm_context llvm)
    {
        // TODO
    }
}