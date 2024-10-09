#pragma once
#include <stack>
#include <vector>
#include <string>
#include <stdexcept>
#include "../Lexer/Token.h"
#include "../Operand/TOperand.hpp"

class Execute {

    public:

        /* CTOR */
        Execute() = delete;
        Execute(std::vector<std::tuple<Token, std::string>> vec);
        ~Execute();
        Execute &operator=(const Execute &rhs);
        Execute(const Execute &rhs);

        /* Get */
        std::stack<IOperand *>   getStack() const;
        std::vector<std::tuple<Token, std::string>> getMdata() const;

        /* Exception */
        class CustomException : public std::runtime_error {
        public:
            explicit CustomException(const std::string &msg) : std::runtime_error(msg) {}
        };

        class EmptyInstruction : public CustomException {
            public:
                explicit EmptyInstruction(const std::string &msg) : CustomException(msg) {}
        };

        class NoExitInstruction : public CustomException {
            public:
                explicit NoExitInstruction(const std::string &msg) : CustomException(msg) {}
        };

    private:

        std::stack<IOperand *> _stack;
        std::vector<std::tuple<Token, std::string>> _mData;
};