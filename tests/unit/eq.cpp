#include "eq.hpp"

void testNum(std::string input, double expected) {
    JL::Parser::Token token(input);
    auto ast = JL::Parser::Num::parse(token);
    cr_assert(*ast == expected);
}

void testVar(std::string input, std::string expected) {
    JL::Parser::Token token(input);
    auto ast = JL::Parser::VarName::parse(token);
    cr_assert(*ast == expected);
}

void testBinop(std::string input, JL::AST::Binop &expected) {
    JL::Parser::Token token(input);
    auto ast = JL::Parser::Binop::parse(token);
    std::cout << *ast << std::endl;
    cr_assert(*ast == expected);
}
