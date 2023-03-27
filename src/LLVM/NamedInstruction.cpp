// #include "NamedInstruction.hpp"

// namespace JL::LLVM {
//     NamedInstruction::NamedInstruction(llvm::Instruction *llvmInstruction, std::string name)
//     : Instruction(llvmInstruction)
//     {
//         this->name = name;
//     }

//     NamedInstruction::NamedInstruction(std::unique_ptr<Constant> constant, std::string name)
//     : Instruction(nullptr)
//     {
//         this->name = name;
//         llvm::Constant *constantValue = constant->get();
//         this->llvmInstruction = llvm::dyn_cast<llvm::Instruction>(constantValue);
//     }

//     NamedInstruction::NamedInstruction(std::unique_ptr<Operation> operation, std::string name)
//     : Instruction(nullptr)
//     {
//         this->name = name;
//         llvm::Value *value = operation->get();
//         this->llvmInstruction = llvm::dyn_cast<llvm::Instruction>(value);
//     }

//     std::string NamedInstruction::getName() const
//     {
//         return this->name;
//     }
// };