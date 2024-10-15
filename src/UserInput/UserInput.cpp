#include "UserInput.hpp"

std::vector<std::string> UserInput::getUserInput()
{
    std::string line;
    std::vector<std::string> vec;

    for (std::string line; std::getline(std::cin, line);) {
        if (line.empty())
            return vec;
        if(line ==  ";;") {
            vec.push_back("exit");
            return vec;
        }
        vec.push_back(line);
    }

    return vec;
}