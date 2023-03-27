#include "Operation.hpp"

namespace JL::LLVM {
    void Operation::createIntOperation(IRBuilder builder, char op, Constant left, Constant right)
    {
        switch (op) {
            case '+':
                this->result = builder.get()->CreateAdd(left.get(), right.get());
                break;
            case '-':
                this->result = builder.get()->CreateSub(left.get(), right.get());
                break;
            case '*':
                this->result = builder.get()->CreateMul(left.get(), right.get());
                break;
            case '/':
                this->result = builder.get()->CreateSDiv(left.get(), right.get());
                break;
            case '%':
                this->result = builder.get()->CreateSRem(left.get(), right.get());
                break;
            default:
                throw Error::NotImplemented("Operation::createIntOperation");
        }
    }

    Operation::Operation(IRBuilder builder, char op, Constant left, Constant right)
    {
        std::shared_ptr<Type> ltype = left.getType();
        std::shared_ptr<Type> rtype = right.getType();

        if (Types::Int::is(*ltype) && Types::Int::is(*rtype)) {
            this->createIntOperation(builder, op, left, right);
        }
    }

    // Operation::Operation(IRBuilder builder, char op, NamedInstruction left, NamedInstruction right)
    // {
    // }

    llvm::Value *Operation::get()
    {
        return this->result;
    }
}