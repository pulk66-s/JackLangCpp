#include "Token.hpp"

namespace JL::Parser {
    Token::Token(std::string content)
    {
        this->content = content;
    }

    char Token::getToken()
    {
        return this->content[this->pos];
    }

    void Token::nextToken()
    {
        this->pos++;
    }
};