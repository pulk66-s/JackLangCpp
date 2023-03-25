#ifndef __JL_PARSER_NUM_HPP__
    #define __JL_PARSER_NUM_HPP__

    #include "AST.hpp"
    #include "Token.hpp"
    #include <memory>

namespace JL::Parser {
    class Num {
        public:
            static std::unique_ptr<AST::Num> parse(Token& token);
    };
};

#endif