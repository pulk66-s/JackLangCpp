#ifndef __EQ_HPP__
    #define __EQ_HPP__

    #include "AST.hpp"
    #include "Parser.hpp"
    #include <string>
    #include <criterion/criterion.h>

void testNum(std::string input, double expected);
void testVar(std::string input, std::string expected);
void testBinop(std::string input, JL::AST::Binop &expected);

#endif