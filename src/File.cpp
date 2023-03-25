#include "File.hpp"

File::File(std::string path)
: path(path) 
{
    this->read();
}

std::string File::read()
{
    std::ifstream file;
    file.open(this->path);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + this->path);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    this->content = buffer.str();
    return this->getContent();
}

std::string File::getContent() const
{
    return this->content;
}

std::string File::getPath() const
{
    return this->path;
}