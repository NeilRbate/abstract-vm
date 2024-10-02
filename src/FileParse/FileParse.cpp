#include "FileParse.hpp"
#include <stdexcept>
#include <fstream>
#include <iostream>

/* Constructor */
FileParse::FileParse(const std::string &filename) {

    // Check if filename is empty
    if (filename.empty()) { throw std::invalid_argument("Filename is empty"); }

    this->_filename = filename;

    // Read file
    try {

        std::ifstream   filecontent(filename);
        if (!filecontent.is_open()) { throw std::runtime_error("Could not open file"); }

        std::string line;

        while(getline(filecontent, line)) { 
            _data.push_back(line);
            line.clear();
        }

        filecontent.close();
    } 
    catch(const std::exception& e) {

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