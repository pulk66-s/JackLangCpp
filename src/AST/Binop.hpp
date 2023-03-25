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
            Binop(char op, std::unique_ptr<Expr> left, std::unique_ptr<Expr> right): op(op), left(std::move(left)), right(std::move(right)) {}
            void print(std::ostream& os) const override {
                os << "Binop(" << op << ", ";
                left->print(os);
                os << ", ";
                right->print(os);
                os << ")";
            }
            bool operator==(const Expr& other) const override {
                if (auto otherBinop = dynamic_cast<const Binop*>(&other)) {
                    return op == otherBinop->op && *left == *otherBinop->left && *right == *otherBinop->right;
                }
                return false;
            }

    };
};

#endif