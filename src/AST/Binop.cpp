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

    std::unique_ptr<LLVM::Operand> Binop::gen(struct JL::LLVM::llvm_context llvm)
    {
        // std::shared_ptr<LLVM::Block> block = llvm.builder->getBlock();
        // std::unique_ptr<LLVM::Operand> leftInstruction = left->gen(llvm);
        // std::unique_ptr<LLVM::Operand> rightInstruction = right->gen(llvm);
        // std::unique_ptr<LLVM::Operation> operation = std::make_unique<LLVM::Operation>(
        //     *llvm.builder,
        //     op,
        //     *leftInstruction,
        //     *rightInstruction
        // );
        // std::unique_ptr<LLVM::Operand> instruction = std::make_unique<LLVM::NamedInstruction>(
        //     std::move(operation),
        //     llvm.nameGenerator->binop()
        // );  

        throw Error::NotImplemented("Binop::gen");
    }
}