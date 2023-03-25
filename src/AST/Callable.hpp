#ifndef __JL_PARSER_AST_CALLABLE_HPP__
    #define __JL_PARSER_AST_CALLABLE_HPP__

    #include "ParserNamespace.hpp"
    #include "AST/Expr.hpp"

    #include <vector>
    #include <memory>

namespace JL::AST {
    class Callable : public Expr {
    private:
        std::string name;
        std::vector<std::unique_ptr<Expr>> args;

    public:
        Callable(std::string name, std::vector<std::unique_ptr<Expr>> args): name(name), args(std::move(args)) {}

    };
}

#endif