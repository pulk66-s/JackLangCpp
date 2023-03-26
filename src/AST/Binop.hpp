#ifndef __JL_PARSER_AST_BINOP_HPP__
    #define __JL_PARSER_AST_BINOP_HPP__

    #include "Expr.hpp"
    #include "ParserNamespace.hpp"

    #include <memory>

namespace JL::AST {
    class Binop : public Expr {
        private:
            char op;
            std::unique_ptr<Expr> left, right;
        
        public:
            Binop(char op, std::unique_ptr<Expr> left, std::unique_ptr<Expr> right);
            void print(std::ostream& os) const;
            bool operator==(const Expr& other) const;
            void gen(struct llvm_context llvm);
    };
};

#endif