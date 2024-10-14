#include "Execute.hpp"

/* CTOR */
Execute::Execute(std::vector<std::tuple<Token, std::string>> vec)
{
    _mData = vec;
    if (vec.size() < 1)
        throw EmptyInstruction("Empty vector");

    if (std::get<0>(vec.back()) != Exit)
        throw NoExitInstruction("No exit instruction at the end of file");
    buildStack();
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
std::stack<const IOperand *> Execute::getStack() const { return _stack; }
std::vector<std::tuple<Token, std::string>> Execute::getMdata() const { return _mData; }

/* Methods */
void Execute::buildStack()
{
    for (auto &item : _mData)
    {
        std::cout << "GET0 " << std::get<0>(item) << " GET1 " <<std::get<1>(item) << std::endl;
        switch (std::get<0>(item))
        {
            case Push: push(std::get<1>(item)); break;
            case Pop: pop(); break;
            case Dump: dump(); break;
            case Assert: assert(std::get<1>(item)); break;
            case Add: add(); break;
            case Sub: sub(); break;
            case Mul: mul(); break;
            case Div: div(); break;
            case Mod: mod(); break;
            case Print: print(); break;
            case Exit: exit(); break;

            default:
                //Throw error
                break;
        }
    }
}

eOperandType findOperandType(std::string value) 
{
    if(value == "int8") return eOperandType::Int8;
    if(value == "int16") return eOperandType::Int16;
    if(value == "int32") return eOperandType::Int32;
    if(value == "float") return eOperandType::Float;
    if(value == "double") return eOperandType::Double;

    throw Execute::InvalidOperandType(value);
}

void Execute::push(std::string value)
{
    std::vector<std::string> temp;
    std::istringstream  stream(value);

    for (std::string line; std::getline(stream, line, '_');)
        temp.push_back(line);
    
    switch (findOperandType(temp[0]))
    {
        case eOperandType::Int8: _stack.push(_factory.createOperand(eOperandType::Int8, temp[1])); break;
        case eOperandType::Int16: _stack.push(_factory.createOperand(eOperandType::Int16, temp[1])); break;
        case eOperandType::Int32: _stack.push(_factory.createOperand(eOperandType::Int32, temp[1])); break;
        case eOperandType::Float: _stack.push(_factory.createOperand(eOperandType::Float, temp[1])); break;
        case eOperandType::Double: _stack.push(_factory.createOperand(eOperandType::Double, temp[1])); break;
    }

}

void Execute::pop()
{
    if (_stack.empty())
        throw Execute::PopOnEmptyStack("Stack is empty, invalid Pop");
    _stack.pop();
}

void Execute::dump()
{
    std::stack<const IOperand *> tmp = _stack;
    while (!tmp.empty())
    {
        std::cout << tmp.top()->toString() << std::endl;
        tmp.pop();
    }
}

void Execute::assert(std::string value)
{
    if (_stack.empty())
        throw Execute::PopOnEmptyStack("Stack in empty, invalid assert");
    
    std::vector<std::string> temp;
    std::istringstream  stream(value);

    for (std::string line; std::getline(stream, line, '_');)
        temp.push_back(line);

    auto type = findOperandType(temp[0]);
    
    if(_stack.top()->getType() != type)
        throw Execute::BadAssert("Assert:" + value + " bad type");
    if(_stack.top()->toString() != temp[1])
        throw Execute::BadAssert("Assert: " + value + " bad type");

}

void Execute::add()
{
    if (_stack.size() < 2)
        throw Execute::PopOnEmptyStack("Stack doesn't have enough elements");
    const IOperand *a = _stack.top();
    _stack.pop();
    const IOperand *b = _stack.top();
    _stack.pop();
    _stack.push(*b + *a);
}

void Execute::sub()
{
    if (_stack.size() < 2)
        throw Execute::PopOnEmptyStack("Stack doesn't have enough elements");
    const IOperand *a = _stack.top();
    _stack.pop();
    const IOperand *b = _stack.top();
    _stack.pop();
    _stack.push(*b - *a);
}

void Execute::mul()
{
    if (_stack.size() < 2)
        throw Execute::PopOnEmptyStack("Stack doesn't have enough elements");
    const IOperand *a = _stack.top();
    _stack.pop();
    const IOperand *b = _stack.top();
    _stack.pop();
    _stack.push(*b * *a);
}

void Execute::div()
{
    if (_stack.size() < 2)
        throw Execute::PopOnEmptyStack("Stack doesn't have enough elements");
    const IOperand *a = _stack.top();
    _stack.pop();
    const IOperand *b = _stack.top();
    _stack.pop();
    _stack.push(*b / *a);
}

void Execute::mod()
{
    if (_stack.size() < 2)
        throw Execute::PopOnEmptyStack("Stack doesn't have enough elements");
    const IOperand *a = _stack.top();
    _stack.pop();
    const IOperand *b = _stack.top();
    _stack.pop();
    _stack.push(*b % *a);
}

void Execute::print()
{
    if (_stack.empty())
        throw Execute::PopOnEmptyStack("Stack is empty");
    if (_stack.top()->getType() != eOperandType::Int8)
        throw Execute::BadAssert("Bad type: print");

    std::cout << static_cast<char>(std::stoi(_stack.top()->toString())) << std::endl;
}

void Execute::exit() { std::exit(EXIT_SUCCESS); }