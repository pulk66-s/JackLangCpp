#ifndef __JL_PARSER_LAUNCH_HPP__
    #define __JL_PARSER_LAUNCH_HPP__

    #include <memory>
    #include <string>

    #include "AST.hpp"
    #include "Token.hpp"
    #include "Expr.hpp"

namespace JL::Parser {
    class Parser {
        private:
            Token token;

        public:
            Parser(std::string content);

            std::unique_ptr<AST::Expr> launch();
    };
};

#endif