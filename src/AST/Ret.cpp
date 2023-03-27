#include "Ret.hpp"

namespace JL::AST {
    Ret::Ret(std::unique_ptr<Expr> expr)
    {
        this->expr = std::move(expr);
    }

    void Ret::print(std::ostream& os) const
    {
        os << "Ret(";
        this->expr->print(os);
        os << ")";
    }

    bool Ret::operator==(const Expr& other) const
    {
        if (auto otherFunc = dynamic_cast<const Ret*>(&other)) {
            return *this->expr == *otherFunc->expr;
        }
        return false;
    }

    std::unique_ptr<LLVM::Operand> Ret::gen(struct JL::LLVM::llvm_context llvm)
    {
        std::unique_ptr<LLVM::Operand> operand = this->expr->gen(llvm);
        if (!operand)
            throw std::runtime_error("Ret: Invalid operand");
        std::unique_ptr<LLVM::Ret> ret = std::make_unique<LLVM::Ret>(llvm, std::move(operand));
        return nullptr;
    }
};