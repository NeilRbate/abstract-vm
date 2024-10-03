#include <array> 
#include <memory>
#include "Operand.cpp"

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
        std::array<IOperand const *(OperandFactory::*)(std::string const &) const, 5> _createOperand 
        {
            &OperandFactory::createInt8,
            &OperandFactory::createInt16,
            &OperandFactory::createInt32,
            &OperandFactory::createFloat,
            &OperandFactory::createDouble
        };

    public:

        /* Coplien */
        OperandFactory();//Default constructor
        OperandFactory(const OperandFactory &rhs) = delete;//copy constructor
        OperandFactory &operator=(const OperandFactory &rhs) = delete;//copy assignment
        ~OperandFactory();//Destructor


        IOperand const *createOperand( eOperandType type, std::string const & value ) const;
};