#include "OperandFactory.hpp"
#include "Operand.cpp"

/* Builder */
IOperand const *OperandFactory::createInt8(std::string const &value) const { 
    return new Int8(std::stoi(value), eOperandType::Int8, ePrecision::int8); 
}


IOperand const *OperandFactory::createInt16(std::string const &value) const {
    return new Int16(std::stoi(value), eOperandType::Int16, ePrecision::int16);
}

IOperand const *OperandFactory::createInt32(std::string const &value) const {
    return new Int32(std::stoi(value), eOperandType::Int32, ePrecision::int32);
}

IOperand const *OperandFactory::createFloat(std::string const &value) const {
    return new Float(std::stof(value), eOperandType::Float, ePrecision::ffloat);
}

IOperand const *OperandFactory::createDouble(std::string const &value) const {
    return new Double(std::stod(value), eOperandType::Double, ePrecision::ddouble);
}

/* CTOR */
OperandFactory::OperandFactory() {
    _createOperand[0] = &OperandFactory::createInt8;
    _createOperand[1] = &OperandFactory::createInt16;
    _createOperand[2] = &OperandFactory::createInt32;
    _createOperand[3] = &OperandFactory::createFloat;
    _createOperand[4] = &OperandFactory::createDouble;
}

/* DCTOR */
OperandFactory::~OperandFactory(){}

/* Factory */
IOperand const *OperandFactory::createOperand(eOperandType type, std::string const &value) const {
    return (this->*_createOperand[static_cast<int>(type)])(value);
}