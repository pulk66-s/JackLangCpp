#ifndef __JL_PARSER_SPACE_HPP__
    #define __JL_PARSER_SPACE_HPP__

    #include "AST.hpp"
    #include "Many.hpp"
    #include "Space.hpp"
    #include "Token.hpp"
    #include "Error/Parse.hpp"

namespace JL::Parser {
    class Space {
        public:
            static std::unique_ptr<AST::Char> parse(Token &token);
    };
};

#endif