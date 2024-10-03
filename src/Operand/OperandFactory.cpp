#include "OperandFactory.hpp"

IOperand const *OperandFactory::createInt8(std::string const &value) const
{
    return nullptr;
}

IOperand const *OperandFactory::createInt16(std::string const &value) const
{
    return nullptr;
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
OperandFactory::OperandFactory() {}

OperandFactory::~OperandFactory(){}

/* Factory */
IOperand const *OperandFactory::createOperand(eOperandType, std::string const &value) const
{
    return this->_createOperand[type](value);
}