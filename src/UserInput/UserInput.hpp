#pragma once

#include <string>
#include <vector>
#include <iostream>

class UserInput {

    public:

        UserInput() = delete;
        ~UserInput() = delete;
        UserInput(const UserInput &rhs) = delete;
        UserInput &operator=(const UserInput &rhs) = delete;

        static std::vector<std::string> getUserInput();
};