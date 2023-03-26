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

    std::string Token::getRest()
    {
        if (this->pos >= this->content.length())
            return "";
        return this->content.substr(this->pos);
    }

    std::string Token::getContent()
    {
        return this->content;
    }
    
    std::size_t Token::save()
    {
        return this->pos;
    }

    void Token::abort(std::string err, std::size_t recul)
    {
        this->pos = recul;
        throw Error::Parse(err);
    }

    void Token::expect(char c)
    {
        if (this->getToken() != c)
            this->abort("Expected '" + std::string(1, c) + "' but got '" + std::string(1, this->getToken()) + "'", this->pos);
        this->nextToken();
    }
};