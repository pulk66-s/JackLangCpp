#ifndef __JL_AST_LINE_HPP__
    #define __JL_AST_LINE_HPP__

    #include "Expr.hpp"
    #include "ASTNamespace.hpp"
    #include <memory>
    #include <iostream>

namespace JL::AST {
    class Line : public Expr {
        private:
            std::unique_ptr<Expr> expr = nullptr;
        
        public:
            Line(std::unique_ptr<Expr> expr): expr(std::move(expr)) {};
            void print(std::ostream &os) const {
                os << "Line (";
                expr->print(os);
                os << ")";
            }
            bool operator==(const Expr &other) const {
                if (const Line* line = dynamic_cast<const Line*>(&other)) {
                    return *this == *line;
                }
                return false;
            }
    };
};

#endif