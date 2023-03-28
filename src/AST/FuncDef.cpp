#include "FuncDef.hpp"

namespace JL::AST {
    FuncDef::FuncDef(
        std::unique_ptr<VarName> name,
        std::vector<std::unique_ptr<VarName>> args,
        std::vector<std::unique_ptr<Expr>> body
    )
    {
        this->name = std::move(name);
        this->args = std::move(args);
        this->body = std::move(body);
    }

    void FuncDef::print(std::ostream& os) const
    {
        os << "FuncDef(";
        name->print(os);
        os << ", [";
        for (auto& arg : args) {
            arg->print(os);
            os << ", ";
        }
        os << "], [";
        for (auto& expr : body) {
            expr->print(os);
            os << ", ";
        }
        os << "])";
    }

    bool FuncDef::operator==(const Expr &other) const
    {
        if (auto otherFunc = dynamic_cast<const FuncDef*>(&other)) {
            return *name == *otherFunc->name
                && args == otherFunc->args
                && body == otherFunc->body;
        }
        return false;
    }

    void FuncDef::generateArgument(struct JL::LLVM::llvm_context llvm, llvm::Argument *arg, std::string name)
    {
        std::unique_ptr<LLVM::Operand> operand = std::make_unique<LLVM::Operand>(arg);
        std::unique_ptr<LLVM::Operand> operandCopy = std::make_unique<LLVM::Operand>(operand->get());
        std::unique_ptr<LLVM::Alloca> alloca = std::make_unique<LLVM::Alloca>(llvm, std::move(operand), name);
        std::unique_ptr<LLVM::Operand> allocaoperand = std::make_unique<LLVM::Operand>(alloca->get()); 
        std::unique_ptr<LLVM::Store> store = std::make_unique<LLVM::Store>(llvm, std::move(operandCopy), std::move(allocaoperand));
    }

    std::unique_ptr<LLVM::Operand> FuncDef::gen(struct JL::LLVM::llvm_context llvm)
    {
        std::string name = this->name->getName();
        std::unique_ptr<LLVM::Types::Int> retType = std::make_unique<LLVM::Types::Int>(*(llvm.context));
        std::vector<std::unique_ptr<LLVM::Type>> args = {};
        for (auto& arg : this->args) {
            args.push_back(std::make_unique<LLVM::Types::Int>(*(llvm.context)));
        }
        LLVM::FunctionType funcType(std::move(retType), std::move(args));
        std::unique_ptr<LLVM::Function> func = std::make_unique<LLVM::Function>(funcType, name, *(llvm.mod));
        std::vector<llvm::Argument *> llvmargs = func->getArguments();
        std::unique_ptr<LLVM::Block> block = std::make_unique<LLVM::Block>(*(llvm.context), "entry", std::move(func));
        llvm.builder->setInsertBlock(std::move(block));
        int i = 0;
        for (llvm::Argument *arg : llvmargs) {
            this->generateArgument(llvm, arg, this->args[i++]->getName());
        }
        for (auto& expr : body) {
            expr->gen(llvm);
        }
        return nullptr;
    }
};