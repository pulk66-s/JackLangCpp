#ifndef __JL_PARSER_EITHER_HPP__
    #define __JL_PARSER_EITHER_HPP__

    #include <memory>
    #include <functional>
    #include "AST.hpp"
    #include "Error/Parse.hpp"
    #include "Token.hpp"
    #include "Expr.hpp"

namespace JL::Parser {
    class Either {
        public:
            static std::unique_ptr<AST::Expr> either(
                Token &token, 
                std::function<std::unique_ptr<AST::Expr>(Token &)> parser1,
                std::function<std::unique_ptr<AST::Expr>(Token &)> parser2
            );
    };
};

#endif