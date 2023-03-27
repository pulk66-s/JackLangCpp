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

    std::unique_ptr<LLVM::Operand> Num::gen(struct JL::LLVM::llvm_context llvm)
    {
        std::unique_ptr<LLVM::Constant> constant = std::make_unique<LLVM::Constant>(
            llvm,
            std::make_unique<LLVM::Types::Int>(*llvm.context),
            this->value
        );
        return std::move(constant);
    }

    bool Num::is(Expr *expr)
    {
        return dynamic_cast<Num*>(expr) != nullptr;
    }

    double Num::get() const
    {
        return this->value;
    }
}