#ifndef __JL_LLVM_NAME_GENERATOR_HPP__
    #define __JL_LLVM_NAME_GENERATOR_HPP__

    #include "LLVMNamespace.hpp"
    #include <unordered_map>
    #include <string>

namespace JL::LLVM {
    class NameGenerator {
        private:
            std::unordered_map<std::string, unsigned int> indexes = {};

        public:
            NameGenerator();
            std::string cstNum();
            std::string binop();
            std::string varDef();
    };
};

#endif