// #ifndef __JL_LLVM_NAMED_INSTRUCTION_HPP__
//     #define __JL_LLVM_NAMED_INSTRUCTION_HPP__

//     #include "LLVMNamespace.hpp"
//     #include "Instruction.hpp"
//     #include "Constant.hpp"
//     #include "llvm/IR/IRBuilder.h"
//     #include "llvm/IR/Module.h"
//     #include <string>

// namespace JL::LLVM {
//     class NamedInstruction : public Instruction {
//         private:
//             std::string name;

//         public:
//             NamedInstruction(llvm::Instruction *llvmInstruction, std::string name);
//             NamedInstruction(std::unique_ptr<Constant> constant, std::string name);
//             NamedInstruction(std::unique_ptr<Operation> operation, std::string name);

//             std::string getName() const;
//     };
// };

// #endif