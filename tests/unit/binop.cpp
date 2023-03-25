#include <criterion/criterion.h>
#include "eq.hpp"

Test(binop, num_num) {
    JL::AST::Binop binop(
        '+',
        std::make_unique<JL::AST::Num>(1),
        std::make_unique<JL::AST::Num>(2)
    );
    testBinop("1 + 2", binop);
}