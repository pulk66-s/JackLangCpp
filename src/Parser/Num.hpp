#ifndef __JL_PARSER_NUM_HPP__
    #define __JL_PARSER_NUM_HPP__

    #include "AST.hpp"
    #include "Token.hpp"
    #include "Error/Parse.hpp"
    #include <memory>
    #include <vector>
    #include <functional>

namespace JL::Parser {
    class Num {
        public:
            static std::unique_ptr<AST::Num> parse(Token& token);
    };
};

#endif