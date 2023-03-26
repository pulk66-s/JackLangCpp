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

    void Line::gen(struct llvm_context llvm)
    {
        expr->gen(llvm);
    }
}
