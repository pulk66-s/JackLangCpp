#include "Parser.hpp"
#include "File.hpp"

int main(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        File file(av[i]);
        JL::Parser::Parser parser(file.getContent());
        std::unique_ptr<JL::AST::Expr> expr = parser.launch();
        std::cout << *expr << std::endl;
    }
    return 0;
}