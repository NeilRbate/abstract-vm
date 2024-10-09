#pragma once

#include <string>
#include <vector>
#include <map>
#include <stdexcept>

class FileParse {

public:

    FileParse() = delete;// No default constructor
    FileParse(const FileParse &rhs);//copy constructor
    FileParse &operator=(const FileParse &rhs);//copy assignment

    ~FileParse();// Destructor

    FileParse(const std::string &filename);// Constructor
    


    std::string getFilename() const;// Getter
    std::vector<std::string> getData() const; // Getter

    /* Custom Exception */

    class CustomException : public std::runtime_error {
        public:
            explicit CustomException(const std::string &message) : std::runtime_error(message) {}
    };

    class EmptyFilenameException : public CustomException {
        public:
            explicit EmptyFilenameException(const std::string &message) : CustomException("Empty filename"){}
    };

    class OpenFailedException : public CustomException {
        public:
            explicit OpenFailedException(const std::string &message) : CustomException("Failed to open file :" + message){}
    };

    /* Stream overload */
    friend std::ostream &operator<<(std::ostream &os, const FileParse &file);

private:

    std::string _filename;
    std::vector<std::string> _data;
};