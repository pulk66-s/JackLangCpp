#ifndef __JL_LLVM_NAME_GENERATOR_HPP__
    #define __JL_LLVM_NAME_GENERATOR_HPP__

    #include "LLVMNamespace.hpp"
    #include "Operand.hpp"
    #include <unordered_map>
    #include <string>

namespace JL::LLVM {
    class NameGenerator {
        private:
            std::unordered_map<std::string, unsigned int> indexes = {};
            std::unordered_map<std::string, std::shared_ptr<Operand>> operands = {};

        public:
            NameGenerator();
            std::string cstNum();
            std::string binop();
            std::string varDef();
            std::string arg();
            void registerOperand(std::string name, std::shared_ptr<Operand> operand);
            std::shared_ptr<Operand> getOperand(std::string name);
    };
};

#endif