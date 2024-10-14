#pragma once
#include <stack>
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>
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
        std::stack<const IOperand *>   getStack() const;
        std::vector<std::tuple<Token, std::string>> getMdata() const;

        /* Methods */
        void    buildStack();
        void    push(std::string value);
        void    pop();
        void    dump();
        void    assert(std::string value);
        void    add();
        void    sub();
        void    mul();
        void    div();
        void    mod();
        void    print();
        void    exit();


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

        class InvalidOperandType : public CustomException {
            public:
                explicit InvalidOperandType(const std::string &msg) : CustomException("Invalid operand type " + msg) {}
        };

        class PopOnEmptyStack : public CustomException {
            public:
                explicit PopOnEmptyStack(const std::string &msg) : CustomException(msg) {}
        };

        class BadAssert : public CustomException {
            public:
                explicit BadAssert(const std::string &msg) : CustomException(msg) {}
        };


    private:

        std::stack<const IOperand *> _stack;
        std::vector<std::tuple<Token, std::string>> _mData;
        OperandFactory  _factory;
};