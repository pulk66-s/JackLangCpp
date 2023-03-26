#ifndef __JL_PARSER_LINE_HPP__
    #define __JL_PARSER_LINE_HPP__

    #include <memory>
    #include <functional>
    #include <vector>
    #include "VarDef.hpp"
    #include "Num.hpp"
    #include "VarName.hpp"
    #include "Binop.hpp"
    #include "AST.hpp"
    #include "Token.hpp"

namespace JL::Parser {
    class Line {
        public:
            static std::unique_ptr<AST::Line> parse(Token &token);
    };
};

#endif