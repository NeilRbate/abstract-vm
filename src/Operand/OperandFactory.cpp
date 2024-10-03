#include "OperandFactory.hpp"
#include "Operand.cpp"

IOperand const *OperandFactory::createInt8(std::string const &value) const
{
    return std::unique_ptr<Int8>(new Int8(std::stoi(value), eOperandType::Int8, ePrecision::int8)).get();
}

IOperand const *OperandFactory::createInt16(std::string const &value) const
{
    return std::unique_ptr<Int16>(new Int16(std::stoi(value), eOperandType::Int16, ePrecision::int16)).get();
}

IOperand const *OperandFactory::createInt32(std::string const &value) const
{
    return nullptr;
}

IOperand const *OperandFactory::createFloat(std::string const &value) const
{
    return nullptr;
}

IOperand const *OperandFactory::createDouble(std::string const &value) const
{
    return nullptr;
}

/* CTOR */
OperandFactory::OperandFactory() {
    _createOperand[0] = &OperandFactory::createInt8;
    _createOperand[1] = &OperandFactory::createInt16;
    _createOperand[2] = &OperandFactory::createInt32;
    _createOperand[3] = &OperandFactory::createFloat;
    _createOperand[4] = &OperandFactory::createDouble;
}

OperandFactory::~OperandFactory(){}

/* Factory */
IOperand const *OperandFactory::createOperand(eOperandType type, std::string const &value) const
{
    return (this->*_createOperand[static_cast<int>(type)])(value);
}