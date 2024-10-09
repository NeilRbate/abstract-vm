#include "Execute.hpp"

/* CTOR */
Execute::Execute(std::vector<std::tuple<Token, std::string>> vec)
{
    _mData = vec;
    if (vec.size() < 1)
        throw EmptyInstruction("Empty vector");

    if (get<0>(*vec.end()) != Exit)
        throw NoExitInstruction("No exit instruction at the end of file");
}

Execute::~Execute() {}

Execute &Execute::operator=(const Execute &rhs)
{
    _mData = rhs.getMdata();
    _stack = rhs.getStack();
    return *this;
}

Execute::Execute(const Execute &rhs) { *this = rhs; }

/* Get */
std::stack<IOperand *> Execute::getStack() const { return _stack; }
std::vector<std::tuple<Token, std::string>> Execute::getMdata() const { return _mData; }
