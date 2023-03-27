#include "Line.hpp"

namespace JL::AST {
    Line::Line(std::unique_ptr<Expr> expr)
    {
        this->expr = std::move(expr);
    }

    void Line::print(std::ostream &os) const
    {
        os << "Line (";
        expr->print(os);
        os << ")";
    }

    bool Line::operator==(const Expr &other) const
    {
        if (const Line* line = dynamic_cast<const Line*>(&other)) {
            return *this == *line;
        }
        return false;
    }

    std::unique_ptr<LLVM::Operand> Line::gen(struct JL::LLVM::llvm_context llvm)
    {
        return expr->gen(llvm);
    }
}
