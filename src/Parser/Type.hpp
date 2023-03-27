#ifndef __JL_PARSER_TYPE_HPP__
    #define __JL_PARSER_TYPE_HPP__

    #include "ParserNamespace.hpp"
    #include "Token.hpp"
    #include "AST.hpp"
    #include <memory>
    #include <vector>
    #include <string>

namespace JL::Parser {
    class Type {
        public:
            static std::unique_ptr<AST::Type> parse(Token &token);
    };
}

#endif