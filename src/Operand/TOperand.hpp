#include "IOperand.hpp"
#include "eOperandType.hpp"
#include "ePrecision.hpp"
#include <typeinfo>
#include <iostream>
#pragma once

template <typename T>
class TOperand : public IOperand {
private:

    T _value;
    eOperandType _type;
    ePrecision _precision;

public:

    TOperand() = delete;

    TOperand<T>(T value, eOperandType type, ePrecision precision) : _value(value), _type(type), _precision(precision) {};

    TOperand(TOperand const & rhs) {
        //Copy operator
    };

    TOperand & operator=(TOperand const & rhs) {
        //Assignement operator
        return *this;
    };

    ~TOperand(){};

    //Implemente interface
    int getPrecision( void ) const { return _precision; } ;
    eOperandType getType( void ) const { return _type; };
    T getValue(void) const { return _value; };

    //Operators overload
    IOperand const *operator+(IOperand const &rhs) const {
            std::cout << "Hello\n";
        return this;
    };

    IOperand const *operator-(IOperand const &rhs) const{return this;};
    IOperand const *operator*(IOperand const &rhs) const{return this;};
    IOperand const *operator/(IOperand const &rhs) const{return this;};
    IOperand const *operator%(IOperand const &rhs) const{return this;};


    std::string const &toString( void ) const { return nullptr;};
};

