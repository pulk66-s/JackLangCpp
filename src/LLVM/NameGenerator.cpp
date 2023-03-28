#include "NameGenerator.hpp"
    #include <iostream>


namespace JL::LLVM {
    NameGenerator::NameGenerator()
    {
        this->indexes["cstNum"] = 0;
        this->indexes["binop"] = 0;
        this->indexes["varDef"] = 0;
        this->indexes["arg"] = 0;
    }

    std::string NameGenerator::cstNum()
    {
        return "cstNum" + std::to_string(this->indexes["cstNum"]++);
    }

    std::string NameGenerator::binop()
    {
        return "binop" + std::to_string(this->indexes["binop"]++);
    }

    std::string NameGenerator::varDef()
    {
        return "varDef" + std::to_string(this->indexes["varDef"]++);
    }

    std::string NameGenerator::arg()
    {
        return "arg" + std::to_string(this->indexes["arg"]++);
    }

    void NameGenerator::registerOperand(std::string name, std::shared_ptr<Operand> operand)
    {
        std::cout << "Registering operand " << name << std::endl;
        this->operands[name] = operand;
    }

    std::shared_ptr<Operand> NameGenerator::getOperand(std::string name)
    {
        std::cout << "Getting operand " << name << std::endl;
        return this->operands[name];
    }
}