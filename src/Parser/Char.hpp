#ifndef __JL_PARSER_CHAR_HPP__
    #define __JL_PARSER_CHAR_HPP__

    #include <memory>
    #include <functional>
    #include "AST.hpp"
    #include "Token.hpp"

namespace JL::Parser {
    class Char {
        public:
            static std::unique_ptr<AST::Char> parse(Token &token, char c);
    };
};

#endif