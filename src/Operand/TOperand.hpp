#include "IOperand.hpp"
#include "OperandFactory.hpp"
#include "eOperandType.h"
#include "ePrecision.h"
#include <typeinfo>
#include <iostream>
#include <limits>
#include <memory>

#pragma once

template <typename T>
class TOperand : public IOperand {
private:

    T _value;
    std::string v;
    eOperandType _type;
    ePrecision _precision;
    OperandFactory  factory;

public:

    /* CTOR */
    TOperand() = delete; //default

    TOperand<T>(T value, eOperandType type, ePrecision precision) 
    : _value(value), _type(type), _precision(precision), v(std::to_string(value)) {}; 

    ~TOperand(){};

    /* Coplien */
    TOperand(TOperand const & rhs) { *this = rhs; };

    TOperand & operator=(TOperand const & rhs) { return factory.createOperand(rhs.getType, rhs.toString()); };


    //Virtual method from IOperand implementation
    int getPrecision( void ) const { return _precision; } ;
    eOperandType getType( void ) const { return _type; };
    std::string const &toString( void ) const { return v; };

    //Operator overload
    IOperand const *operator+(IOperand const &rhs) const {

        IOperand    *ptr = rhs;
        if (this->getType() > ptr.getType()) {
        }
        return this;
    };

    IOperand const *operator-(IOperand const &rhs) const{ return this; };
    IOperand const *operator*(IOperand const &rhs) const{ return this; };
    IOperand const *operator/(IOperand const &rhs) const{ return this; };
    IOperand const *operator%(IOperand const &rhs) const{ return this; };


    /* Methods */

};

