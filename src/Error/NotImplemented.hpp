#ifndef __JL_ERROR_NOT_IMPLEMENTED_HPP__
    #define __JL_ERROR_NOT_IMPLEMENTED_HPP__
 
    #include <string>
    #include <exception>

namespace JL::Error {
    class NotImplemented : public std::exception {
    private:
        std::string message;
    public:
        NotImplemented(std::string message): message(message) {};
        const char* what() const noexcept override {
            return this->message.c_str();
        }
    };
};

#endif