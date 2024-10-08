#include "IOperand.hpp"
#include "OperandFactory.hpp"
#include "eOperandType.h"
#include "ePrecision.h"
#include <typeinfo>
#include <iostream>
#include <limits>
#include <memory>
#include <cmath>

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
    : _value(value), _type(type), _precision(precision), v(std::to_string(value)) {}; //CTOR

    ~TOperand(){};

    /* Coplien */
    TOperand(TOperand const & rhs) { *this = rhs; };// copy constructor
    TOperand & operator=(TOperand const & rhs) { return factory.createOperand(rhs.getType(), rhs.toString()); };// copy assignment
    TOperand(TOperand && rhs) { *this = std::move(rhs); };// move constructor
    TOperand & operator=(TOperand && rhs) { return factory.createOperand(rhs.getType(), rhs.toString()); };// move assignment


    //Virtual method from IOperand implementation
    int getPrecision( void ) const { return _precision; } ;
    eOperandType getType( void ) const { return _type; };
    std::string const &toString( void ) const { return v; };

    //Operator overload
    IOperand const *operator+(IOperand const &rhs) const  {
        double result = std::stod(this->toString()) + std::stod(rhs.toString());

        if (rhs.getPrecision() == this->getPrecision()) {
            return factory.createOperand(rhs.getType(), std::to_string(result));
        } else if (rhs.getPrecision() > this->getPrecision()) {
            return factory.createOperand(rhs.getType(), std::to_string(result));
        }
        return factory.createOperand(this->getType(), std::to_string(result));
    };

    IOperand const *operator-(IOperand const &rhs) const {
        double result = std::stod(this->toString()) - std::stod(rhs.toString());

        if (rhs.getPrecision() == this->getPrecision()) {
            return factory.createOperand(rhs.getType(), std::to_string(result));
        } else if (rhs.getPrecision() > this->getPrecision()) {
            return factory.createOperand(rhs.getType(), std::to_string(result));
        }
        return factory.createOperand(this->getType(), std::to_string(result));
    };

    IOperand const *operator*(IOperand const &rhs) const {
        double result = std::stod(this->toString()) * std::stod(rhs.toString());

        if (rhs.getPrecision() == this->getPrecision()) {
            return factory.createOperand(rhs.getType(), std::to_string(result));
        } else if (rhs.getPrecision() > this->getPrecision()) {
            return factory.createOperand(rhs.getType(), std::to_string(result));
        }
        return factory.createOperand(this->getType(), std::to_string(result));
    };

    IOperand const *operator/(IOperand const &rhs) const {

        if (std::stod(this->toString()) == 0) {
            throw DivisionByZeroException();
        } else if (std::stod(rhs.toString()) == 0) {
            throw DivisionByZeroException();
        }

        double result = std::stod(this->toString()) / std::stod(rhs.toString());

        if (rhs.getPrecision() == this->getPrecision()) {
            return factory.createOperand(rhs.getType(), std::to_string(result));
        } else if (rhs.getPrecision() > this->getPrecision()) {
            return factory.createOperand(rhs.getType(), std::to_string(result));
        }
        return factory.createOperand(this->getType(), std::to_string(result));
    };

    IOperand const *operator%(IOperand const &rhs) const {

        if (std::stod(this->toString()) == 0) {
            throw ModuloByZeroException();
        } else if (std::stod(rhs.toString()) == 0) {
            throw ModuloByZeroException();
        }

        double result = std::fmod(std::stod(this->toString()), std::stod(rhs.toString()));

        if (rhs.getPrecision() == this->getPrecision()) {
            return factory.createOperand(rhs.getType(), std::to_string(result));
        } else if (rhs.getPrecision() > this->getPrecision()) {
            return factory.createOperand(rhs.getType(), std::to_string(result));
        }
        return factory.createOperand(this->getType(), std::to_string(result));
    };


    /* Methods */

    /* Exception */ 

    class OverflowException : public std::exception {
        public:
            virtual const char *what() const throw() {
                return "Overflow Exception";
            }
    };

    class UnderflowException : public std::exception {
        public:
            virtual const char *what() const throw() {
                return "Underflow Exception";
            }
    };

    class DivisionByZeroException : public std::exception {
        public:
            virtual const char *what() const throw() {
                return "Division by zero Exception";
            }
    };

    class ModuloByZeroException : public std::exception {
        public:
            virtual const char *what() const throw() {
                return "Modulo by zero Exception";
            }
    };

};
