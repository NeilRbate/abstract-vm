#pragma once

#include <string>
#include <vector>
#include <map>

class FileParse {

public:

    FileParse() = delete;// No default constructor
    FileParse(const FileParse &rhs);//copy constructor
    FileParse &operator=(const FileParse &rhs);//copy assignment

    ~FileParse();// Destructor

    FileParse(const std::string &filename);// Constructor
    


    std::string getFilename() const;// Getter
    std::vector<std::string> getData() const; // Getter


    friend std::ostream &operator<<(std::ostream &os, const FileParse &file);

private:

    std::string _filename;
    std::vector<std::string> _data;
    std::map<std::string, std::string> _dataMap;
};