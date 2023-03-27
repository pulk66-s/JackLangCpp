#include "Parser.hpp"
#include "File.hpp"
#include "AST.hpp"
#include "LLVM.hpp"
#include <memory>

void genllvm(std::unique_ptr<JL::AST::Expr> expr)
{
    std::shared_ptr<JL::LLVM::Context> context = std::make_shared<JL::LLVM::Context>();
    std::shared_ptr<JL::LLVM::IRBuilder> builder = std::make_shared<JL::LLVM::IRBuilder>(*context);
    std::shared_ptr<JL::LLVM::Module> mod = std::make_shared<JL::LLVM::Module>("test", *context);
    std::shared_ptr<JL::LLVM::NameGenerator> nameGenerator = std::make_shared<JL::LLVM::NameGenerator>();
    struct JL::LLVM::llvm_context llvm = {
        .context = context,
        .builder = builder,
        .mod = mod,
        .nameGenerator = nameGenerator
    };
    expr->gen(llvm);
    llvm.mod->print();
}

int main(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        File file(av[i]);
        JL::Parser::Parser parser(file.getContent());
        try {
            std::unique_ptr<JL::AST::Expr> expr = parser.launch();
            std::cout << *expr << std::endl;
            genllvm(std::move(expr));
        } catch (JL::Error::Parse &e) {
            // std::cout << e.what() << std::endl;
        }
    }
    return 0;
}