#include "IOperand.hpp"
#include "eOperandType.hpp"

#pragma once

template <typename T>
class Operand : IOperand {

private:

    std::string _value;
    eOperandType _type;
    ePrecision _precision;

public:

    Operand(std::string value, eOperandType type, ePrecision precision) {
        _type = type;
        _precision = precision;
        _value = value;
    };

    Operand(Operand const & rhs) { *this = rhs; };

    Operand & operator=(Operand const & rhs) {
        _value = rhs.getValue();
        _type = rhs.getType();
        _precision = rhs.getPrecision();
        return *this;
    };

    ~Operand() {};

    //Implemente interface
    int getPrecision( void ) const { return _precision; };
    eOperandType getType( void ) const { return _type; };
    T getValue(void) const { return _value; };

    //Operators overload
    IOperand const *operator+(IOperand const &rhs) const {
        if (rhs.getPrecision > getPrecision()) {
            this._
        }
    };
    IOperand const *operator-(IOperand const &rhs) const;
    IOperand const *operator*(IOperand const &rhs) const;
    IOperand const *operator/(IOperand const &rhs) const;
    IOperand const *operator%(IOperand const &rhs) const;


    std::string const &toString( void ) const { return std::to_string(_value); };

};

