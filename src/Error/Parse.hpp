#ifndef __JL_ERROR_PARSE_HPP__
    #define __JL_ERROR_PARSE_HPP__
 
    #include <string>
    #include <exception>

namespace JL::Error {
    class Parse : public std::exception {
    private:
        std::string message;
    public:
        Parse(std::string message): message(message) {};
        const char* what() const noexcept override {
            return this->message.c_str();
        }
    };
};


#endif