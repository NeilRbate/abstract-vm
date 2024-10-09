#include "FileParse.hpp"
#include <stdexcept>
#include <fstream>
#include <iostream>

/* Constructor */
FileParse::FileParse(const std::string &filename) {

    try {
        // Check if filename is empty
        if (filename.empty()) { throw EmptyFilenameException(filename); }

        this->_filename = filename;

        // Read file
        std::ifstream   filecontent(filename);
        if (!filecontent.is_open()) { throw OpenFailedException(filename); }

        std::string line;

        while(getline(filecontent, line)) { 
            _data.push_back(line);
            line.clear();
        }

        filecontent.close();

        
    } 
    catch(const CustomException &e) {

        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }
}

/* Copy constructor */
FileParse::FileParse(const FileParse &rhs) { *this = rhs; }

/* Copy operator */
FileParse &FileParse::operator=(const FileParse &rhs)
{
    this->_filename = rhs.getFilename();
    this->_data = rhs.getData();
    return *this;
}

/* Destructor */
FileParse::~FileParse() {}

/* Getter */
std::string FileParse::getFilename() const { return this->_filename; }
std::vector<std::string> FileParse::getData() const { return this->_data; }

/* Ostream overload */
std::ostream &operator<<(std::ostream &os, const FileParse &file) {

    os << "Filename: " << file.getFilename() << std::endl;
    for (auto &line : file.getData()) {
        os << line << std::endl;
    }

    return os;
}