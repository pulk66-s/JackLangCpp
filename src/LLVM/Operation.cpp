#include "Operation.hpp"
#include <iostream>

namespace JL::LLVM {
    Operation::Operation(struct llvm_context llvm, char op, std::unique_ptr<Operand> left, std::unique_ptr<Operand> right)
    {
        this->updateValue(llvm, op, std::move(left), std::move(right));
    }

    void Operation::updateValue(struct llvm_context llvm, char op, std::unique_ptr<Operand> left, std::unique_ptr<Operand> right)
    {
        llvm::Value *leftValue = left->get();
        llvm::Value *rightValue = right->get();

        switch (op) {
            case '+':
                this->value = llvm.builder->get()->CreateAdd(leftValue, rightValue);
                break;
            case '-':
                this->value = llvm.builder->get()->CreateSub(leftValue, rightValue);
                break;
            case '*':
                this->value = llvm.builder->get()->CreateMul(leftValue, rightValue);
                break;
            case '/':
                this->value = llvm.builder->get()->CreateSDiv(leftValue, rightValue);
                break;
            default:
                throw Error::NotImplemented("Operation not implemented");
        }
    }
}