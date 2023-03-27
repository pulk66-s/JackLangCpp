#ifndef __JL_LLVM_TYPES_INT_HPP__
    #define __JL_LLVM_TYPES_INT_HPP__

    #include "LLVM/LLVMNamespace.hpp"
    #include "LLVM/Type.hpp"
    #include "LLVM/Context.hpp"

namespace JL::LLVM::Types {
    class Int : public Type {
        public:
            Int(Context ctx);
            static bool is(Type type);
    };
}

#endif