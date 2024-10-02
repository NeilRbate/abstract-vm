#include "Operand.hpp"



/* Factory */
IOperand const *Operand::createOperand(eOperandType type, std::string const &value) const
{
    return std::unique_ptr<IOperand>(new Operand(type, value)).release();
}

/* Coplien */
Operand::Operand(const Operand &rhs) { *this = rhs; }

Operand &Operand::operator=(const Operand &rhs)
{
    if (this != &rhs)
    {
        _value = rhs.toString();
        _type = rhs.getType();
        _precision = rhs.getPrecision();
    }
    return *this;
}

Operand::~Operand(){}

/* Constructor */
Operand::Operand(eOperandType type, const std::string &value)
{
    _value = value;
    _type = type;

    switch (type)
    {
        case eOperandType::Int8:
            _precision = ePrecision::Int8;
            break;
        case eOperandType::Int16:
            _precision = ePrecision::Int16;
            break;  
        case eOperandType::Int32:
            _precision = ePrecision::Int32;
            break;
        case eOperandType::Float:
            _precision = ePrecision::Float;
            break;  
        case eOperandType::Double:
            _precision = ePrecision::Double;
            break;
        default:
            _precision = ePrecision::none;
            break;
    }
}

/* Accessor */
int Operand::getPrecision(void) const { return _precision; }
eOperandType Operand::getType(void) const { return _type; }
std::string const &Operand::toString(void) const { return _value; }

IOperand const *Operand::compute(std::string const &value1, std::string const &value2, ePrecision type, eOperandType operandType)
{
    std::string result;

    switch (type)
    {
        case ePrecision::Int8:
            result = std::to_string(stoi(value1) + std::stoi(value2));
            break;
        case ePrecision::Int16:
            result = std::to_string(stoi(value1) + std::stoi(value2));
            break;
        case ePrecision::Int32:
            result = std::to_string(stoi(value1) + std::stoi(value2));
            break;
        case ePrecision::Float:
            result = std::to_string(stof(value1) + std::stof(value2));
            break;
        case ePrecision::Double:
            result = std::to_string(stod(value1) + std::stod(value2));
            break;
    }

    return createOperand(operandType, result);
}

IOperand const *Operand::operator+(IOperand const &rhs) const 
{
    if (rhs.getPrecision() == _precision) {
        return createOperand(_type, std::to_string(std::stod(_value) + std::stod(rhs.toString())));
    } else if (rhs.getPrecision() > _precision) {

        return createOperand(rhs.getType(), std::to_string(std::stod(_value) + std::stod(rhs.toString())));
    } else {
        return createOperand(_type, std::to_string(std::stod(_value) + std::stod(rhs.toString())));
    }
}