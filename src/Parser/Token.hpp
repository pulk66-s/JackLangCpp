#ifndef __JL_PARSER_TOKEN_HPP__
    #define __JL_PARSER_TOKEN_HPP__

    #include "AST.hpp"
    #include "Error/Parse.hpp"
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
            std::string getRest();
            std::string getContent();
            std::size_t save();
            void expect(char c);
            void expect(std::string str);
            void abort(std::string err, std::size_t recul = 0);
            void restore(std::size_t pos);
    };
};

#endif