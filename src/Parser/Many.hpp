#ifndef __PARSER_MANY_HPP__
    #define __PARSER_MANY_HPP__

    #include "AST.hpp"
    #include "ParserNamespace.hpp"
    #include "Error/Parse.hpp"
    #include <functional>
    #include <memory>
    #include <vector>

namespace JL::Parser {
    class Many {
        public:
            static std::vector<std::unique_ptr<AST::Expr>> parse(Token &token, std::function<std::unique_ptr<AST::Expr>(Token &)> parser);
    };
}

#endif