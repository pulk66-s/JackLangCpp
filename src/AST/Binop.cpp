#include "Binop.hpp"

namespace JL::AST {
    Binop::Binop(char op, std::unique_ptr<Expr> left, std::unique_ptr<Expr> right)
    {
        this->op = op;
        this->left = std::move(left);
        this->right = std::move(right);
    }

    void Binop::print(std::ostream& os) const
    {
        os << "Binop(" << op << ", ";
        left->print(os);
        os << ", ";
        right->print(os);
        os << ")";
    }

    bool Binop::operator==(const Expr& other) const
    {
        if (auto otherBinop = dynamic_cast<const Binop*>(&other)) {
            return op == otherBinop->op && *left == *otherBinop->left && *right == *otherBinop->right;
        }
        return false;
    }

    void Binop::gen(struct llvm_context llvm)
    {
        // TODO
    }
}