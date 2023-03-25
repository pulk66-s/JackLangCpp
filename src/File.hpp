#ifndef __JL_FILE_HPP__
    #define __JL_FILE_HPP__

    #include <string>
    #include <fstream>
    #include <sstream>

class File {
    private:
        std::string path;
        std::string content;
    public:
        File(std::string path);

        std::string read();
        std::string getContent() const;
        std::string getPath() const;
};

#endif