#ifndef __JL_PARSER_TOKEN_HPP__
    #define __JL_PARSER_TOKEN_HPP__

    #include "AST.hpp"
    #include <string>

namespace JL::Parser {
    class Token {
        private:
            std::string content = "";
            std::size_t pos = 0;

        public:
            Token(std::string content);

            char getToken();
            void nextToken();
    };
};

#endif