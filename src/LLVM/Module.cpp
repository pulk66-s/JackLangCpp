#include "Module.hpp"

namespace JL::LLVM {
    Module::Module(std::string name, Context ctx)
    {
        this->name = name;
        this->mod = std::make_unique<llvm::Module>(this->name, *ctx.get());
    }

    void Module::print() const
    {
        this->mod->print(llvm::outs(), nullptr);
    }

    llvm::Module *Module::get()
    {
        return this->mod.get();
    }
};