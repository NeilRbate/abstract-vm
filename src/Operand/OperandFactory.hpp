#pragma once
#include <array> 
#include <memory>
#include <iostream>
#include <stdexcept>
#include "IOperand.hpp"

#pragma once


class OperandFactory {

    private:

        /* Methods */
        IOperand const * createInt8( std::string const & value ) const;
        IOperand const * createInt16( std::string const & value ) const;
        IOperand const * createInt32( std::string const & value ) const;
        IOperand const * createFloat( std::string const & value ) const;
        IOperand const * createDouble( std::string const & value ) const;

        /* Array of operand created function */
        std::array<IOperand const *(OperandFactory::*)(std::string const &) const, 5> _createOperand;

    public:

        /* Coplien */
        OperandFactory();//Default constructor
        OperandFactory(const OperandFactory &rhs) = delete;//copy constructor
        OperandFactory &operator=(const OperandFactory &rhs) = delete;//copy assignment
        OperandFactory(OperandFactory &&rhs) = delete;//move constructor
        OperandFactory &operator=(OperandFactory &&rhs) = delete;//move assignment
        ~OperandFactory();//Destructor


        IOperand const *createOperand( eOperandType type, std::string const & value ) const;

        class CustomException : public std::runtime_error {
        public:
            explicit CustomException(const std::string &msg) : std::runtime_error(msg) {}
        };

        class OverflowException : public CustomException {
            public:
                explicit OverflowException(const std::string &msg) : CustomException("Overflow on value : " + msg) {}
        };

        class UnderflowException : public CustomException {
            public:
                explicit UnderflowException(const std::string &msg) : CustomException("Underflow on value : " + msg) {}
        };
};