#pragma once

#include <vector>
#include <string>
#include <stdexcept>
#include <map>
#include <algorithm>
#include "Token.h"


class Lexer {

    public:

        /* CTOR */
        Lexer() = delete;// default constructor
        Lexer(const std::vector<std::string> &data);// constructor
        ~Lexer();// destructor
        Lexer(Lexer const &rhs);// copy constructor
        Lexer &operator=(Lexer const &rhs);// assignement operator


        /* Exception */
        class CustomException : std::runtime_error {
            public: 
                explicit CustomException(const std::string &msg) : std::runtime_error(msg) {}
        };

        class Emptyexception : CustomException {
            public:
                explicit Emptyexception(const std::string &msg) : CustomException(msg) {}
        };

        /* Get */
        std::vector<std::string> getData() const;
        std::map<Token, std::string> getMdata() const;

    private:

        /* Declaration */
        std::vector<std::string> _data;
        std::map<Token, std::string> _mdata;

        /* Private methods */
        void syntaxAnalysis();
        bool isSemicolon(const char c) const;
        std::tuple<Token, std::string> extractToken(const std::string &str) const;

};