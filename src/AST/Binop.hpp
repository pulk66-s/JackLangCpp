#ifndef __JL_PARSER_AST_BINOP_HPP__
    #define __JL_PARSER_AST_BINOP_HPP__

    #include "Expr.hpp"
    #include "ParserNamespace.hpp"

    #include <memory>

namespace JL::AST {
    class Binop : public Expr {
        private:
            char op;
            std::shared_ptr<Expr> left, right;
        
        public:
            Binop(char op, std::shared_ptr<Expr> left, std::shared_ptr<Expr> right): op(op), left(left), right(right) {}
    };
};

#endif